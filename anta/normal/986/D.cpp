#include "bits/stdc++.h"
using namespace std;

/*



*/

#ifdef __GNUC__
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <emmintrin.h>
#endif

namespace uint_util {
	template<typename T> struct Utils {};

	template<> struct Utils<uint32_t> {
		static void umul_full(uint32_t a, uint32_t b, uint32_t *lo, uint32_t *hi) {
			const uint64_t c = (uint64_t)a * b;
			*lo = (uint32_t)c;
			*hi = (uint32_t)(c >> 32);
		}
		static  uint32_t umul_hi(uint32_t a, uint32_t b) {
			return (uint32_t)((uint64_t)a * b >> 32);
		}
		static uint32_t mulmod_invert(uint32_t b, uint32_t n) {
			return ((uint64_t)b << 32) / n;
		}

		static uint32_t umul_lo(uint32_t a, uint32_t b) {
			return a * b;
		}
		static uint32_t mulmod_precalculated(uint32_t a, uint32_t b, uint32_t n, uint32_t bninv) {
			const auto q = umul_hi(a, bninv);
			uint32_t r = a * b - q * n;
			if (r >= n) r -= n;
			return r;
		}

		static uint32_t invert_twoadic(uint32_t x) {
			uint32_t i = x, p;
			do {
				p = i * x;
				i *= 2 - p;
			} while (p != 1);
			return i;
		}
	};
}

namespace bigbase_util {
	template<typename T, T BigBase> struct Utils {};
	template<uint32_t BigBase> struct Utils<uint32_t, BigBase> {
		using W = uint32_t;

		static W add_carry(W a, W b, W *lo) {
			W sum = a + b;
			W carry = sum >= BigBase;
			*lo = sum - (BigBase & (~carry + 1));
			return carry;
		}
		static uint32_t add_carry_3(W a, W b, W c, W *lo) {
			return add_carry_4(a, b, c, 0, lo);
		}
		static W add_carry_4(W a, W b, W c, W d, W *lo) {
			W sum = a + b + c + d;
			W carry = 0;
			if (sum >= BigBase * 2) carry = 2, sum -= BigBase * 2;
			if (sum >= BigBase) ++ carry, sum -= BigBase;
			*lo = sum;
			return carry;
		}
		static W add_carry_full(W a, W b, W carry, W *lo) {
			return add_carry_3(a, b, carry, lo);
		}
		static W subtract_borrow(W a, W b, W *lo) {
			return 1 - add_carry(a, BigBase - b, lo);
		}
		static W subtract_borrow_full(W a, W b, W borrow, W *lo) {
			return 1 - add_carry(a, BigBase - b - borrow, lo);
		}
		static void umul_full(W a, W b, W *lo, W *hi) {
			auto prod = (uint64_t)a * b;
			*lo = prod % BigBase;
			*hi = (W)(prod / BigBase);
		}

		//a * b + c < BigBase^3
		//a, b, c are not reduced
		static uint64_t multiply_add_double_carry(uint64_t a, uint32_t b, uint64_t c, W *lo) {
			W alo = a % BigBase, blo = b % BigBase, clo = c % BigBase;
			uint64_t ahi = a / BigBase, bhi = b / BigBase, chi = c / BigBase;
			W prodlo, prodhi;
			umul_full(alo, blo, &prodlo, &prodhi);
			uint64_t carry = add_carry(prodlo, c % BigBase, lo);
			carry += prodhi;
			carry += alo * bhi;
			carry += ahi * blo;
			carry += ahi * bhi * BigBase;
			carry += chi;
			return carry;
		}
	};
};


namespace modnum {

	template<typename NumType> struct ModNumTypes {
		using Util = uint_util::Utils<NumType>;

		template<int Lazy> struct LazyModNum;

		//x < Lazy * P
		template<int Lazy>
		struct LazyModNum {
			NumType x;
			LazyModNum() : x() {}
			template<int L>
			explicit LazyModNum(LazyModNum<L> t) : x(t.x) { static_assert(L <= Lazy, "invalid conversion"); }

			static LazyModNum raw(NumType x) {
				LazyModNum r; r.x = x;
				return r;
			}

			template<int L>
			static LazyModNum *coerceArray(LazyModNum<L> *a) { return reinterpret_cast<LazyModNum*>(a); }

			bool operator==(LazyModNum that) const {
				static_assert(Lazy == 1, "cannot compare");
				return x == that.x;
			}
		};

		typedef LazyModNum<1> ModNum;

		class ModInfo {
		public:
			enum {
				MAX_ROOT_ORDER = 23
			};

		private:
			NumType P, P2;
			ModNum _one;
			NumType _twoadic_inverse;
			NumType _order;
			NumType _one_P_inv;	//floor(W * (W rem P) / P)

			bool _support_fft;
			ModNum _roots[MAX_ROOT_ORDER + 1], _inv_roots[MAX_ROOT_ORDER + 1];
			ModNum _inv_two_powers[MAX_ROOT_ORDER + 1];

		public:
			NumType getP() const { return P; }
			NumType get_twoadic_inverse() const { return _twoadic_inverse; }

			ModNum one() const { return _one; }

			ModNum to_alt(NumType x) const {
				return ModNum::raw(Util::mulmod_precalculated(x, _one.x, P, _one_P_inv));
			}
			NumType from_alt(ModNum x) const {
				return _reduce(x.x, 0);
			}

			bool support_fft() const { return _support_fft; }

			ModNum root(int n) const {
				assert(support_fft());
				if (n > 0) {
					assert(n <= MAX_ROOT_ORDER);
					return _roots[n];
				} else if (n < 0) {
					assert(n >= -MAX_ROOT_ORDER);
					return _inv_roots[-n];
				} else {
					return one();
				}
			}

			ModNum inv_two_power(int n) const {
				assert(support_fft());
				assert(0 <= n && n <= MAX_ROOT_ORDER);
				return _inv_two_powers[n];
			}

			ModNum add(ModNum a, ModNum b) const {
				auto c = a.x + b.x;
				if (c >= P) c -= P;
				return ModNum::raw(c);
			}

			ModNum sub(ModNum a, ModNum b) const {
				auto c = a.x + (P - b.x);
				if (c >= P) c -= P;
				return ModNum::raw(c);
			}

			LazyModNum<4> add_lazy(LazyModNum<2> a, LazyModNum<2> b) const {
				return LazyModNum<4>::raw(a.x + b.x);
			}
			LazyModNum<4> sub_lazy(LazyModNum<2> a, LazyModNum<2> b) const {
				return LazyModNum<4>::raw(a.x + (P2 - b.x));
			}

			ModNum mul(ModNum a, ModNum b) const {
				NumType lo, hi;
				Util::umul_full(a.x, b.x, &lo, &hi);
				return ModNum::raw(_reduce(lo, hi));
			}
			ModNum sqr(ModNum a) const {
				return mul(a, a);
			}

			template<int LA, int LB>
			LazyModNum<2> mul_lazy(LazyModNum<LA> a, LazyModNum<LB> b) const {
				static_assert(LA + LB <= 5, "too lazy");
				NumType lo, hi;
				Util::umul_full(a.x, b.x, &lo, &hi);
				return LazyModNum<2>::raw(_reduce_lazy(lo, hi));
			}

			ModNum pow(ModNum a, NumType k) const {
				LazyModNum<2> base{ a }, res{ one() };
				while (1) {
					if (k & 1) res = mul_lazy(res, base);
					if (k >>= 1) base = mul_lazy(base, base);
					else break;
				}
				return lazy_reduce_1(res);
			}

			ModNum inverse(ModNum a) const {
				return pow(a, _order - 1);
			}

			//a < 2P, res < P
			ModNum lazy_reduce_1(LazyModNum<2> a) const {
				NumType x = a.x;
				if (x >= P) x -= P;
				return ModNum::raw(x);
			}
			//a < 4P, res < 2P
			LazyModNum<2> lazy_reduce_2(LazyModNum<4> a) const {
				NumType x = a.x;
				if (x >= P2) x -= P2;
				return LazyModNum<2>::raw(x);
			}

		private:
			NumType _reduce(NumType lo, NumType hi) const {
				const auto q = Util::umul_lo(lo, _twoadic_inverse);
				const auto h = Util::umul_hi(q, P);
				NumType t = hi + P - h;
				if (t >= P) t -= P;
				return t;
			}

			NumType _reduce_lazy(NumType lo, NumType hi) const {
				const auto q = Util::umul_lo(lo, _twoadic_inverse);
				const auto h = Util::umul_hi(q, P);
				return hi + P - h;
			}

		public:
			static ModInfo make(NumType P, NumType order = NumType(-1)) {
				ModInfo res;

				res.P = P;
				res.P2 = P * 2;
				res._one.x = ~Util::umul_lo(Util::mulmod_invert(1, P), P) + 1;
				res._order = order == NumType(-1) ? P - 1 : order;
				res._twoadic_inverse = Util::invert_twoadic(P);

				res._one_P_inv = Util::mulmod_invert(res._one.x, P);

				res._support_fft = false;

				assert(res.mul(res.one(), res.one()) == res.one());

				return res;
			}

			static ModInfo make_support_fft(NumType P, NumType order, NumType original_root, int valuation) {
				ModInfo res = make(P, order);
				_compute_fft_info(res, original_root, valuation);
				return res;
			}

		private:
			static void _compute_fft_info(ModInfo &res, NumType original_root, int valuation) {
				assert(res.P <= 1ULL << (sizeof(NumType) * 8 - 2));
				assert(valuation >= MAX_ROOT_ORDER);

				res._support_fft = true;

				ModNum max_root = res.to_alt(original_root);
				for (int i = valuation; i > MAX_ROOT_ORDER; -- i)
					max_root = res.sqr(max_root);

				res._roots[MAX_ROOT_ORDER] = max_root;
				for (int i = MAX_ROOT_ORDER - 1; i >= 0; -- i)
					res._roots[i] = res.sqr(res._roots[i + 1]);

				res._inv_roots[MAX_ROOT_ORDER] = res.inverse(max_root);
				for (int i = MAX_ROOT_ORDER - 1; i >= 0; -- i)
					res._inv_roots[i] = res.sqr(res._inv_roots[i + 1]);

				res._inv_two_powers[0] = res.one();
				res._inv_two_powers[1] = res.inverse(res.add(res.one(), res.one()));
				for (int i = 1; i < MAX_ROOT_ORDER; ++ i)
					res._inv_two_powers[i] = res.mul(res._inv_two_powers[1], res._inv_two_powers[i - 1]);

				assert(res.mul(res._roots[1], res._inv_roots[1]) == res.one());
				assert(res.root(0) == res.one());
				assert(!(res.root(1) == res.one()));
			}
		};
	};

}

namespace fft {

	using namespace modnum;

	using NumType = uint32_t;

	using ModNumType = ModNumTypes<NumType>;
	template<int Lazy>
	using LazyModNum = ModNumType::LazyModNum<Lazy>;
	using ModNum = ModNumType::ModNum;
	using ModInfo = ModNumType::ModInfo;

	using ModNumType32 = ModNumTypes<uint32_t>;
	using ModNum32 = ModNumType32::ModNum;
	using ModInfo32 = ModNumType32::ModInfo;

	inline __m128i mod_lazy_reduce_2_sse2(const __m128i &a, const __m128i &p2, const __m128i &signbit) {
		const auto mask = _mm_cmpgt_epi32(_mm_xor_si128(p2, signbit), _mm_xor_si128(a, signbit));
		const auto sub = _mm_andnot_si128(mask, p2);
		return _mm_sub_epi32(a, sub);
	}

	inline __m128i mod_reduce_lazy_sse2(const __m128i &a, const __m128i &p, const __m128i &twoadic_inverse) {
		const auto q = _mm_mul_epu32(a, twoadic_inverse);
		const auto h = _mm_shuffle_epi32(_mm_mul_epu32(q, p), _MM_SHUFFLE(3, 3, 1, 1));
		return _mm_add_epi32(a, _mm_sub_epi32(p, h));
	}

	inline __m128i mod_mul_lazy_sse2(const __m128i &a, const __m128i &b, const __m128i &p, const __m128i &twoadic_inverse) {
		const auto a02 = _mm_shuffle_epi32(a, _MM_SHUFFLE(2, 2, 0, 0));
		const auto a13 = _mm_shuffle_epi32(a, _MM_SHUFFLE(3, 3, 1, 1));
		const auto b02 = _mm_shuffle_epi32(b, _MM_SHUFFLE(2, 2, 0, 0));
		const auto b13 = _mm_shuffle_epi32(b, _MM_SHUFFLE(3, 3, 1, 1));

		const auto prod02 = _mm_mul_epu32(a02, b02);
		const auto prod13 = _mm_mul_epu32(a13, b13);

		const auto res02 = mod_reduce_lazy_sse2(prod02, p, twoadic_inverse);
		const auto res13 = mod_reduce_lazy_sse2(prod13, p, twoadic_inverse);

		const auto shuffled02 = _mm_shuffle_epi32(res02, _MM_SHUFFLE(0, 0, 3, 1));
		const auto shuffled13 = _mm_shuffle_epi32(res13, _MM_SHUFFLE(0, 0, 3, 1));

		return _mm_unpacklo_epi32(shuffled02, shuffled13);
	}

	inline __m128i mod_mul_sse2(const __m128i &a, const __m128i &b, const __m128i &p, const __m128i &twoadic_inverse) {
		__m128i t = mod_mul_lazy_sse2(a, b, p, twoadic_inverse);
		const auto mask = _mm_cmpgt_epi32(p, t);	//signed compare
		const auto sub = _mm_andnot_si128(mask, p);
		return _mm_sub_epi32(t, sub);
	}

	inline __m128i mod_add_lazy_sse2(const __m128i &a, const __m128i &b) {
		return _mm_add_epi32(a, b);
	}
	inline __m128i mod_sub_lazy_sse2(const __m128i &a, const __m128i &b, const __m128i &p2) {
		return _mm_add_epi32(a, _mm_sub_epi32(p2, b));
	}

	void ntt_dit_lazy_core_sse2(LazyModNum<2> *f_inout, int n, int sign, const ModInfo &mod) {
		LazyModNum<4> * const f = LazyModNum<4>::coerceArray(f_inout);

		int N = 1 << n;

		if (n <= 1) {
			if (n == 0)
				return;

			const auto a = f_inout[0];
			const auto b = f_inout[1];

			f_inout[0] = mod.lazy_reduce_2(mod.add_lazy(a, b));
			f_inout[1] = mod.lazy_reduce_2(mod.sub_lazy(a, b));
			return;
		}

		if (n & 1) {
			for (int i = 0; i < N; i += 2) {
				const auto a = f_inout[i + 0];
				const auto b = f_inout[i + 1];

				f[i + 0] = mod.add_lazy(a, b);
				f[i + 1] = mod.sub_lazy(a, b);
			}
		}

		if ((n & 1) == 0) {
			const auto imag = mod.root(2 * sign);
			for (int i = 0; i < N; i += 4) {
				const auto a0 = f_inout[i + 0];
				const auto a2 = f_inout[i + 1];
				const auto a1 = f_inout[i + 2];
				const auto a3 = f_inout[i + 3];

				const auto t02 = mod.lazy_reduce_2(mod.add_lazy(a0, a2));
				const auto t13 = mod.lazy_reduce_2(mod.add_lazy(a1, a3));

				f[i + 0] = mod.add_lazy(t02, t13);
				f[i + 2] = mod.sub_lazy(t02, t13);

				const auto u02 = mod.lazy_reduce_2(mod.sub_lazy(a0, a2));
				const auto u13 = mod.mul_lazy(mod.sub_lazy(a1, a3), imag);

				f[i + 1] = mod.add_lazy(u02, u13);
				f[i + 3] = mod.sub_lazy(u02, u13);
			}
		} else {
			const auto imag = mod.root(2 * sign);
			const auto omega = mod.root(3 * sign);

			for (int i = 0; i < N; i += 8) {
				const auto a0 = mod.lazy_reduce_2(f[i + 0]);
				const auto a2 = mod.lazy_reduce_2(f[i + 2]);
				const auto a1 = mod.lazy_reduce_2(f[i + 4]);
				const auto a3 = mod.lazy_reduce_2(f[i + 6]);

				const auto t02 = mod.lazy_reduce_2(mod.add_lazy(a0, a2));
				const auto t13 = mod.lazy_reduce_2(mod.add_lazy(a1, a3));

				f[i + 0] = mod.add_lazy(t02, t13);
				f[i + 4] = mod.sub_lazy(t02, t13);

				const auto u02 = mod.lazy_reduce_2(mod.sub_lazy(a0, a2));
				const auto u13 = mod.mul_lazy(mod.sub_lazy(a1, a3), imag);

				f[i + 2] = mod.add_lazy(u02, u13);
				f[i + 6] = mod.sub_lazy(u02, u13);
			}

			ModNum w = omega, w2 = imag, w3 = mod.mul(w2, w);

			for (int i = 1; i < N; i += 8) {
				const auto a0 = mod.lazy_reduce_2(f[i + 0]);
				const auto a2 = mod.mul_lazy(f[i + 2], w2);
				const auto a1 = mod.mul_lazy(f[i + 4], w);
				const auto a3 = mod.mul_lazy(f[i + 6], w3);

				const auto t02 = mod.lazy_reduce_2(mod.add_lazy(a0, a2));
				const auto t13 = mod.lazy_reduce_2(mod.add_lazy(a1, a3));

				f[i + 0] = mod.add_lazy(t02, t13);
				f[i + 4] = mod.sub_lazy(t02, t13);

				const auto u02 = mod.lazy_reduce_2(mod.sub_lazy(a0, a2));
				const auto u13 = mod.mul_lazy(mod.sub_lazy(a1, a3), imag);

				f[i + 2] = mod.add_lazy(u02, u13);
				f[i + 6] = mod.sub_lazy(u02, u13);
			}
		}

		for (int m = 4 + (n & 1); m <= n; m += 2) {
			int M = 1 << m, M_4 = M >> 2;
			const auto o = mod.root(m * sign), o2 = mod.root((m - 1) * sign), o4 = mod.root((m - 2) * sign);

			const auto p = _mm_set1_epi32(mod.getP());
			const auto p2 = _mm_set1_epi32(mod.getP() * 2);
			const auto twoadic_inverse = _mm_set1_epi32(mod.get_twoadic_inverse());
			const auto imag = _mm_set1_epi32(mod.root(2 * sign).x);
			const auto omega = _mm_set1_epi32(o4.x);
			const auto signbit = _mm_set1_epi32((int)(1U << 31));

			__m128i w = _mm_set_epi32(mod.mul(o, o2).x, o2.x, o.x, mod.one().x);

			for (int j = 0; j < M_4; j += 4) {
				const auto w2 = mod_mul_sse2(w, w, p, twoadic_inverse);
				const auto w3 = mod_mul_sse2(w2, w, p, twoadic_inverse);

				for (int i = j; i < N; i += M) {
					const auto f0 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + M_4 * 0));
					const auto f1 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + M_4 * 1));
					const auto f2 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + M_4 * 2));
					const auto f3 = _mm_loadu_si128(reinterpret_cast<__m128i*>(f + i + M_4 * 3));

					const auto a0 = mod_lazy_reduce_2_sse2(f0, p2, signbit);
					const auto a2 = mod_mul_lazy_sse2(f1, w2, p, twoadic_inverse);
					const auto a1 = mod_mul_lazy_sse2(f2, w, p, twoadic_inverse);
					const auto a3 = mod_mul_lazy_sse2(f3, w3, p, twoadic_inverse);

					const auto t02 = mod_lazy_reduce_2_sse2(mod_add_lazy_sse2(a0, a2), p2, signbit);
					const auto t13 = mod_lazy_reduce_2_sse2(mod_add_lazy_sse2(a1, a3), p2, signbit);

					const auto r0 = mod_add_lazy_sse2(t02, t13);
					const auto r2 = mod_sub_lazy_sse2(t02, t13, p2);

					const auto u02 = mod_lazy_reduce_2_sse2(mod_sub_lazy_sse2(a0, a2, p2), p2, signbit);
					const auto u13 = mod_mul_lazy_sse2(mod_sub_lazy_sse2(a1, a3, p2), imag, p, twoadic_inverse);

					const auto r1 = mod_add_lazy_sse2(u02, u13);
					const auto r3 = mod_sub_lazy_sse2(u02, u13, p2);

					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + M_4 * 0), r0);
					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + M_4 * 1), r1);
					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + M_4 * 2), r2);
					_mm_storeu_si128(reinterpret_cast<__m128i*>(f + i + M_4 * 3), r3);
				}

				w = mod_mul_sse2(w, omega, p, twoadic_inverse);
			}
		}

		for (int i = 0; i < N; ++ i)
			f_inout[i] = mod.lazy_reduce_2(f[i]);
	}

	void ntt_dit_lazy_core(LazyModNum<2> *f_inout, int n, int sign, const ModInfo &mod) {
		ntt_dit_lazy_core_sse2(f_inout, n, sign, mod);
	}

	template<typename T>
	void bit_reverse_permute(T *f, int n) {
		int N = 1 << n, N_2 = N >> 1, r = 0;
		for (int x = 1; x < N; ++ x) {
			int h = N_2;
			while (((r ^= h) & h) == 0) h >>= 1;
			if (r > x) swap(f[x], f[r]);
		}
	}

	void ntt_dit_lazy(LazyModNum<2> *f, int n, int sign, const ModInfo &mod) {
		bit_reverse_permute(f, n);
		ntt_dit_lazy_core(f, n, sign, mod);
	}

	template<int LF, int LG>
	void componentwise_product_lazy(LazyModNum<2> *res, const LazyModNum<LF> *f, const LazyModNum<LG> *g, int N, const ModInfo &mod) {
		for (int i = 0; i < N; ++ i)
			res[i] = mod.mul_lazy(f[i], g[i]);
	}

	void normalize_and_lazy_reduce(LazyModNum<2> *f, int n, const ModInfo &mod) {
		const auto f_out = ModNum::coerceArray(f);
		int N = 1 << n;
		ModNum inv = mod.inv_two_power(n);
		assert(mod.mul(inv, mod.to_alt(N)) == mod.one());
		for (int i = 0; i < N; ++ i)
			f_out[i] = mod.lazy_reduce_1(mod.mul_lazy(f[i], inv));
	}

	void convolute(ModNum *f_in, ModNum *g_in, int n, const ModInfo &mod) {
		assert(mod.support_fft());
		const auto f = LazyModNum<2>::coerceArray(f_in);
		const auto g = LazyModNum<2>::coerceArray(g_in);
		ntt_dit_lazy(f, n, +1, mod);
		ntt_dit_lazy(g, n, +1, mod);
		componentwise_product_lazy(f, f, g, 1 << n, mod);
		ntt_dit_lazy(f, n, -1, mod);
		normalize_and_lazy_reduce(f, n, mod);
	}

	void auto_convolute(ModNum *f_in, int n, const ModInfo &mod) {
		assert(mod.support_fft());
		const auto f = LazyModNum<2>::coerceArray(f_in);
		ntt_dit_lazy(f, n, +1, mod);
		componentwise_product_lazy(f, f, f, 1 << n, mod);
		ntt_dit_lazy(f, n, -1, mod);
		normalize_and_lazy_reduce(f, n, mod);
	}
}

namespace multiprime_fft {
	enum { MULTIPRIME_NUM = 3 };

	static const fft::ModInfo fft_prime_mod0 = fft::ModInfo::make_support_fft(998244353, -1, 31, 23);
	static const fft::ModInfo fft_prime_mod1 = fft::ModInfo::make_support_fft(897581057, -1, 45, 23);
	static const fft::ModInfo fft_prime_mod2 = fft::ModInfo::make_support_fft(880803841, -1, 211, 23);
	const fft::ModInfo * const fft_prime_mods[MULTIPRIME_NUM] = { &fft_prime_mod0, &fft_prime_mod1, &fft_prime_mod2 };

	using Util = bigbase_util::Utils<uint32_t, (uint32_t)1000000000>;


	//template<typename Utils>
	uint64_t multiprime_compose(Util::W *res, const fft::ModNum *f[MULTIPRIME_NUM], int N, const fft::ModInfo * const mods[MULTIPRIME_NUM]) {
		const auto f0 = f[0], f1 = f[1], f2 = f[2];
		const auto &mod0 = *mods[0], &mod1 = *mods[1], &mod2 = *mods[2];
		const auto P0 = mod0.getP(), P1 = mod1.getP(), P2 = mod2.getP();
		const auto t1 = mod1.inverse(mod1.to_alt(P0));
		const auto t2 = mod2.inverse(mod2.to_alt((uint64_t)P0 * P1 % P2));
		const auto p01 = (uint64_t)P0 * P1;

		uint64_t carry = 0;
		for (int i = 0; i < N; ++ i) {
			const auto a0 = mod0.from_alt(f0[i]), a1 = mod1.from_alt(f1[i]), a2 = mod2.from_alt(f2[i]);
			const auto d1 = mod1.sub(mod1.to_alt(a1), mod1.to_alt(a0));
			const auto h1 = mod1.from_alt(mod1.mul(d1, t1));
			const auto a01 = a0 + (uint64_t)P0 * h1;
			const auto d2 = mod2.sub(mod2.to_alt(a2), mod2.to_alt(a01 % P2));
			const auto h2 = mod2.from_alt(mod2.mul(d2, t2));
			carry = Util::multiply_add_double_carry(p01, h2, a01 + carry, &res[i]);
		}
		return carry;
	}

	void multiprime_decompose(fft::ModNum *res[MULTIPRIME_NUM], const Util::W *f, int N, const fft::ModInfo * const mods[MULTIPRIME_NUM]) {
		for (int i = 0; i < N; ++ i) {
			const auto a = f[i];
			for (int k = 0; k < MULTIPRIME_NUM; ++ k)
				res[k][i] = mods[k]->to_alt(a);
		}
	}

	uint64_t multiprime_convolute(Util::W *res, int resN, const Util::W *f, int fN, const Util::W *g, int gN, int n) {
		int N = 1 << n;
		assert(fN <= N && gN <= N && resN <= N);
		//implicit zero-fill
		unique_ptr<fft::ModNum[]> workspace(new fft::ModNum[N * MULTIPRIME_NUM * 2]);
		fft::ModNum *fs[MULTIPRIME_NUM], *gs[MULTIPRIME_NUM];
		for (int k = 0; k < MULTIPRIME_NUM; ++ k) {
			fs[k] = workspace.get() + (k * 2 + 0) * N;
			gs[k] = workspace.get() + (k * 2 + 1) * N;
		}
		multiprime_decompose(fs, f, fN, fft_prime_mods);
		multiprime_decompose(gs, g, gN, fft_prime_mods);
		for (int k = 0; k < MULTIPRIME_NUM; ++ k)
			fft::convolute(fs[k], gs[k], n, *fft_prime_mods[k]);
		return multiprime_compose(res, const_cast<const fft::ModNum **>(fs), resN, fft_prime_mods);
	}

	uint64_t multiprime_auto_convolute(Util::W *res, int resN, const Util::W *f, int fN, int n) {
		int N = 1 << n;
		assert(fN <= N && resN <= N);
		unique_ptr<fft::ModNum[]> workspace(new fft::ModNum[N * MULTIPRIME_NUM]);
		fft::ModNum *fs[MULTIPRIME_NUM];
		for (int k = 0; k < MULTIPRIME_NUM; ++ k)
			fs[k] = workspace.get() + k * N;
		multiprime_decompose(fs, f, fN, fft_prime_mods);
		for (int k = 0; k < MULTIPRIME_NUM; ++ k)
			fft::auto_convolute(fs[k], n, *fft_prime_mods[k]);
		return multiprime_compose(res, const_cast<const fft::ModNum **>(fs), resN, fft_prime_mods);
	}
}

/*



*/
namespace big_int {

	/*
	
	
	
	*/

	struct BigInt {
		typedef uint32_t W;
		static const W SmallBase = 10;
		static const W BigBase = 1000000000;
		static const int BaseSize = 9;

		static W ZeroW() { return W(); }
		static W OneW() { return W(1); }
		static bool IsZeroW(W x) { return x == ZeroW(); }
		using BigBaseUtil = bigbase_util::Utils<W, BigBase>;

		std::vector<W> limbs;

		BigInt() {}
		explicit BigInt(W c0) : limbs(1, c0) {
			if (c0 >= BigBase) {
				limbs[0] %= BigBase;
				limbs.push_back(c0 / BigBase);
			}
		}
		explicit BigInt(const char *str) {
			int len = (int)strlen(str);
			int size = (len + (BaseSize - 1)) / BaseSize;
			resize(size);
			int j = len;
			for (int i = 0; i < size; ++ i) {
				W x = ZeroW(), p = 1;
				for (int k = 0; k < BaseSize && j > 0; ++ k) {
					x += p * (str[-- j] - '0');
					p *= SmallBase;
				}
				limbs[i] = x;
			}
		}

		static BigInt Zero() { return BigInt(); }
		static BigInt One() { return BigInt(OneW()); }

		void resize(int n) { limbs.resize(n); }
		void clear() { limbs.clear(); }

		W *data() { return limbs.empty() ? NULL : &limbs[0]; }
		const W *data() const { return limbs.empty() ? NULL : &limbs[0]; }

		int size() const { return static_cast<int>(limbs.size()); }
		bool empty() const { return limbs.empty(); }

		bool normalized() const { return limbs.empty() || !IsZeroW(limbs.back()); }

		void normalize() { while (!empty() && IsZeroW(limbs.back())) limbs.pop_back(); }
		
		bool operator<(const BigInt &that) const { return compare(*this, that) < 0; }
		bool operator<=(const BigInt &that) const { return compare(*this, that) <= 0; }
		bool operator==(const BigInt &that) const { return compare(*this, that) == 0; }
		bool operator!=(const BigInt &that) const { return compare(*this, that) != 0; }
		bool operator>=(const BigInt &that) const { return compare(*this, that) >= 0; }
		bool operator>(const BigInt &that) const { return compare(*this, that) > 0; }

		static int compare(const BigInt &p, const BigInt &q) {
			return _compare(p.data(), p.size(), q.data(), q.size());
		}

		BigInt &operator+=(const BigInt &that) {
			int m = size(), n = that.size();
			if (m < n) resize(n);
			append_carry(*this, _add(data(), data(), size(), that.data(), n));
			return *this;
		}
		BigInt operator+(const BigInt &that) const {
			return BigInt(*this) += that;
		}

		BigInt &operator-=(const BigInt &that) {
			int m = size(), n = that.size();
			if (m < n) resize(n);
			if (!IsZeroW(_subtract(data(), data(), size(), that.data(), n))) {
				std::cerr << "BigInt: negative values are not implemented" << std::endl;
				abort();
			}
			normalize();
			return *this;
		}
		BigInt operator-(const BigInt &that) const {
			return BigInt(*this) -= that;
		}

		BigInt operator*(const BigInt &that) const {
			BigInt r;
			multiply(r, *this, that);
			return r;
		}

		BigInt &operator*=(const BigInt &that) {
			multiply(*this, *this, that);
			return *this;
		}

		static void append_carry(BigInt &p, W carry) {
			if (!IsZeroW(carry))
				p.limbs.push_back(carry);
		}

		static void multiply(BigInt &res, const BigInt &p, const BigInt &q) {
			int pn = p.size(), qn = q.size();

			if (pn < qn)
				return multiply(res, q, p);

			if (qn == 0) {
				res.limbs.clear();
				return;
			} else if (qn == 1) {
				res.resize(p.size());
				append_carry(res, _multiply_1(res.data(), p.data(), p.size(), q.limbs[0]));
				return;
			}

			if (&res == &p || &res == &q) {
				BigInt tmp;
				multiply(tmp, p, q);
				res = tmp;
				return;
			}

			res.resize(pn + qn);
			_multiply_select_method(res.data(), p.data(), pn, q.data(), qn);
			res.normalize();
		}
		
		static int MULTIPRIME_FFT_THRESHOLD;

		std::string to_string() const {
			int n = size();
			if (n == 0) return "0";
			std::string res(n * BaseSize, '0');
			int j = 0;
			for (int i = 0; i < n; ++ i) {
				W x = limbs[i];
				for (int k = 0; k < BaseSize; ++ k) {
					res[j ++] = '0' + x % SmallBase;
					x /= SmallBase;
				}
			}
			while (res.size() > 1 && res.back() == '0') res.pop_back();
			std::reverse(res.begin(), res.end());
			return res;
		}

		friend std::ostream &operator<<(std::ostream &os, const BigInt &p) {
			return os << p.to_string();
		}

		friend std::istream &operator>>(std::istream &is, BigInt &p) {
			std::string str;
			is >> str;
			p = BigInt(str.c_str());
			return is;
		}

	private:
		static void _fill_zero(W *res, int n);
		static void _copy(W *res, const W *p, int n);

		static int _compare(const W *p, int pn, const W *q, int qn);

		static W _add_1(W *p, int n, W c0);
		static W _subtract_1(W *p, int n, W c0);

		static W _add(W *res, const W *p, int pn, const W *q, int qn);
		static W _subtract(W *res, const W *p, int pn, const W *q, int qn);

		static W _multiply_1(W *p, const W *q, int n, W c0);
		static W _multiply_add_1(W *res, const W *p, W c0, const W *q, int n);

		static void _multiply_select_method(W *res, const W *p, int pn, const W *q, int qn);
		static void _square_select_method(W *res, const W *p, int pn);

		static void _schoolbook_multiplication(W *res, const W *p, int pn, const W *q, int qn);

		static void _multiprime_fft(W *res, const W *p, int pn, const W *q, int qn);
	};
	int BigInt::MULTIPRIME_FFT_THRESHOLD = 8;


	void BigInt::_fill_zero(W *res, int n) {
		for (int i = 0; i < n; ++ i)
			res[i] = ZeroW();
	}

	void BigInt::_copy(W *res, const W *p, int n) {
		for (int i = 0; i < n; ++ i)
			res[i] = p[i];
	}

	int BigInt::_compare(const W *p, int pn, const W *q, int qn) {
		if (pn < qn) return -_compare(q, qn, p, pn);
		for (int i = pn - 1; i >= qn; -- i) if (!IsZeroW(p[i]))
			return 1;
		for (int i = qn - 1; i >= 0; -- i) if (p[i] != q[i])
			return p[i] > q[i] ? 1 : -1;
		return 0;
	}

	BigInt::W BigInt::_add_1(W *p, int n, W c0) {
		W carry = c0;
		for (int i = 0; i < n && !IsZeroW(carry); ++ i)
			carry = BigBaseUtil::add_carry(p[i], carry, &p[i]);
		return carry;
	}

	BigInt::W BigInt::_subtract_1(W *p, int n, W c0) {
		W borrow = c0;
		for (int i = 0; i < n && !IsZeroW(borrow); ++ i)
			borrow = BigBaseUtil::subtract_borrow(p[i], borrow, &p[i]);
		return borrow;
	}

	BigInt::W BigInt::_add(W *res, const W *p, int pn, const W *q, int qn) {
		W carry = ZeroW();
		for (int i = 0; i < qn; ++ i)
			carry = BigBaseUtil::add_carry_full(p[i], q[i], carry, &res[i]);
		return _add_1(res + qn, pn - qn, carry);
	}

	BigInt::W BigInt::_subtract(W *res, const W *p, int pn, const W *q, int qn) {
		W borrow = ZeroW();
		for (int i = 0; i < qn; ++ i)
			borrow = BigBaseUtil::subtract_borrow_full(p[i], q[i], borrow, &res[i]);
		return _subtract_1(res + qn, pn - qn, borrow);
	}

	BigInt::W BigInt::_multiply_1(W *p, const W *q, int n, W c0) {
		W carry = ZeroW();
		for (int i = 0; i < n; ++ i) {
			W lo, hi;
			BigBaseUtil::umul_full(q[i], c0, &lo, &hi);
			W carry2 = BigBaseUtil::add_carry(carry, lo, &p[i]);
			carry = hi + carry2;
		}
		return carry;
	}

	BigInt::W BigInt::_multiply_add_1(W *res, const W *p, W c0, const W *q, int n) {
		W carry = ZeroW();
		for (int i = 0; i < n; ++ i) {
			W lo, hi;
			BigBaseUtil::umul_full(p[i], c0, &lo, &hi);
			W carry2 = BigBaseUtil::add_carry_3(res[i], lo, carry, &res[i]);
			carry = hi + carry2;
		}
		return carry;

	}

	void BigInt::_multiply_select_method(W *res, const W *p, int pn, const W *q, int qn) {
		if (pn < qn) std::swap(p, q), std::swap(pn, qn);
		assert(res != p && res != q && pn >= qn && qn > 0);
		if (qn < MULTIPRIME_FFT_THRESHOLD) {
			_schoolbook_multiplication(res, p, pn, q, qn);
		} else {
			_multiprime_fft(res, p, pn, q, qn);
		}
	}

	void BigInt::_square_select_method(W *res, const W *p, int pn) {
		return _multiply_select_method(res, p, pn, p, pn);
	}

	void BigInt::_schoolbook_multiplication(W *res, const W *p, int pn, const W *q, int qn) {
		assert(res != p && res != q && pn >= qn && qn > 0);
		res[pn] = _multiply_1(res, p, pn, q[0]);
		for (int i = 1; i < qn; ++ i)
			res[i + pn] = _multiply_add_1(res + i, p, q[i], res + i, pn);
	}

	void BigInt::_multiprime_fft(W *res, const W *p, int pn, const W *q, int qn) {
		int resn = pn + qn;
		assert(resn >= 3);
		int n = 0;
		while ((1 << n) < resn) ++ n;
		if (p == q) {
			assert(pn == qn);
			multiprime_fft::multiprime_auto_convolute(res, resn, p, pn, n);
		} else {
			multiprime_fft::multiprime_convolute(res, resn, p, pn, q, qn, n);
		}
	}
}

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }

int main() {
	using namespace big_int;
	static char S[1500002];
	while (~scanf("%s", S)) {
		BigInt N(S);
		if (N == BigInt(1)) {
			puts("1");
			continue;
		}
		int len = (int)strlen(S);
		int a = max(0, (int)((len - 1) * log(10.) / log(3.) - 5));
		BigInt A(1);
		{
			BigInt P(3);
			for (int k = 0; (a >> k) != 0; ++ k) {
				if (a >> k & 1) A *= P;
				P *= P;
			}
		}
		const int INF = 0x3f3f3f3f;
		int ans = INF;
		for (int t : {1, 2, 4}) {
			BigInt X = A * BigInt(t);
			int cost = a * 3 + (t == 1 ? 0 : t);
			while (X < N) {
				X *= BigInt(3);
				cost += 3;
			}
			amin(ans, cost);
		}
		printf("%d\n", ans);
	}
}