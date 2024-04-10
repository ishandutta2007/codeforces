#include "bits/stdc++.h"
using namespace std;

#include <emmintrin.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

struct ModInt {
	using NumType = uint32_t;
	using ModNumType = modnum::ModNumTypes<NumType>;
	using ModNum = ModNumType::ModNum;
	using ModInfo = ModNumType::ModInfo;

public:
	ModNum x;

	ModInt() : x() {}
	ModInt(NumType num) : x(mod.to_alt(num)) {}
	ModInt(int num) : x(mod.to_alt(num >= 0 ? num : mod.getP() + num % (int)mod.getP())) {}

	NumType get() const { return mod.from_alt(x); }

	static ModInt raw(ModNum x) { ModInt r; r.x = x; return r; }
	static ModInt one() { return raw(mod.one()); }

	ModInt operator+(ModInt that) const { return raw(mod.add(x, that.x)); }
	ModInt &operator+=(ModInt that) { return *this = *this + that; }

	ModInt operator-(ModInt that) const { return raw(mod.sub(x, that.x)); }
	ModInt &operator-=(ModInt that) { return *this = *this - that; }

	ModInt operator-() const { return raw(mod.sub(ModNum(), x)); }

	ModInt operator*(ModInt that) const { return raw(mod.mul(x, that.x)); }
	ModInt &operator*=(ModInt that) { return *this = *this * that; }

	ModInt inverse() const { return raw(mod.inverse(x)); }
	ModInt operator/(ModInt that) const { return *this * that.inverse(); }
	ModInt &operator/=(ModInt that) { return *this = *this / that.inverse(); }

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return !(*this == that); }

private:
	static ModInfo mod;

public:
	static const ModInfo &get_mod_info() { return mod; }
	static NumType getMod() { return mod.getP(); }

	static void set_mod(NumType P, NumType order = -1) {
		mod = ModInfo::make(P, order);
	}

	static void set_fft_mod(NumType P, NumType order, NumType omega, int valuation) {
		mod = ModInfo::make_support_fft(P, order, omega, valuation);
	}
};

ModInt::ModInfo ModInt::mod;
typedef ModInt mint;

namespace mod_polynomial {

	struct Polynomial {
		typedef mint R;
		static R ZeroR() { return R(); }
		static R OneR() { return R::one(); }
		static bool IsZeroR(R r) { return r == ZeroR(); }

		struct NumberTable {
			std::vector<R> natural_numbers;
			std::vector<R> inverse_numbers;
			std::vector<R> factorials;
			std::vector<R> inverse_factorials;

			int size() const { return (int)natural_numbers.size(); }
		};

		std::vector<R> coeffs;

		Polynomial() {}
		explicit Polynomial(R c0) : coeffs(1, c0) {}
		explicit Polynomial(R c0, R c1) : coeffs(2) { coeffs[0] = c0, coeffs[1] = c1; }
		template<typename It> Polynomial(It be, It en) : coeffs(be, en) {}

		static Polynomial Zero() { return Polynomial(); }
		static Polynomial One() { return Polynomial(OneR()); }
		static Polynomial X() { return Polynomial(ZeroR(), OneR()); }

		void resize(int n) { coeffs.resize(n); }
		void clear() { coeffs.clear(); }

		R *data() { return coeffs.empty() ? NULL : &coeffs[0]; }
		const R *data() const { return coeffs.empty() ? NULL : &coeffs[0]; }

		int size() const { return static_cast<int>(coeffs.size()); }
		bool empty() const { return coeffs.empty(); }
		int degree() const { return size() - 1; }

		bool normalized() const { return coeffs.empty() || coeffs.back() != ZeroR(); }
		bool monic() const { return !coeffs.empty() && coeffs.back() == OneR(); }

		R get(int i) const { return 0 <= i && i < size() ? coeffs[i] : ZeroR(); }

		void set(int i, R x) {
			if (size() <= i)
				resize(i + 1);
			coeffs[i] = x;
		}

		void normalize() { while (!empty() && IsZeroR(coeffs.back())) coeffs.pop_back(); }

		R evaluate(R x) const {
			if (empty()) return R();
			R r = coeffs.back();
			for (int i = size() - 2; i >= 0; -- i) {
				r *= x;
				r += coeffs[i];
			}
			return r;
		}

		Polynomial &operator+=(const Polynomial &that) {
			int m = size(), n = that.size();
			if (m < n) resize(n);
			_add(data(), that.data(), n);
			return *this;
		}
		Polynomial operator+(const Polynomial &that) const {
			return Polynomial(*this) += that;
		}

		Polynomial &operator-=(const Polynomial &that) {
			int m = size(), n = that.size();
			if (m < n) resize(n);
			_subtract(data(), that.data(), n);
			return *this;
		}
		Polynomial operator-(const Polynomial &that) const {
			return Polynomial(*this) -= that;
		}

		Polynomial &operator*=(R r) {
			_multiply_1(data(), size(), r);
			return *this;
		}
		Polynomial operator*(R r) const {
			Polynomial res;
			res.resize(size());
			_multiply_1(res.data(), data(), size(), r);
			return res;
		}

		Polynomial operator*(const Polynomial &that) const {
			Polynomial r;
			multiply(r, *this, that);
			return r;
		}

		Polynomial &operator*=(const Polynomial &that) {
			multiply(*this, *this, that);
			return *this;
		}

		static void multiply(Polynomial &res, const Polynomial &p, const Polynomial &q) {
			int pn = p.size(), qn = q.size();

			if (pn < qn)
				return multiply(res, q, p);

			if (&res == &p || &res == &q) {
				Polynomial tmp;
				multiply(tmp, p, q);
				res = tmp;
				return;
			}

			if (qn == 0) {
				res.coeffs.clear();
			} else {
				res.resize(pn + qn - 1);
				_multiply_select_method(res.data(), p.data(), pn, q.data(), qn);
			}
		}

		Polynomial operator-() const {
			Polynomial res;
			res.resize(size());
			_negate(res.data(), data(), size());
			return res;
		}

		Polynomial precomputeRevInverse(int n) const {
			Polynomial res;
			res.resize(n);
			_precompute_reverse_inverse(res.data(), n, data(), size());
			return res;
		}

		static void divideRemainderPrecomputedRevInverse(Polynomial &quot, Polynomial &rem, const Polynomial &p, const Polynomial &q, const Polynomial &inv) {
			assert(&quot != &p && &quot != &q && &quot != &inv);
			int pn = p.size(), qn = q.size();
			assert(inv.size() >= pn - qn + 1);
			quot.resize(std::max(0, pn - qn + 1));
			rem.resize(qn - 1);
			_divide_remainder_precomputed_inverse(quot.data(), rem.data(), p.data(), pn, q.data(), qn, inv.data());
			quot.normalize();
			rem.normalize();
		}

		Polynomial computeRemainderPrecomputedRevInverse(const Polynomial &q, const Polynomial &inv) const {
			Polynomial quot, rem;
			divideRemainderPrecomputedRevInverse(quot, rem, *this, q, inv);
			return rem;
		}

		Polynomial powerMod(long long K, const Polynomial &q) const {
			int qn = q.size();
			assert(K >= 0 && qn > 0);
			assert(q.monic());
			if (qn == 1) return Polynomial();
			if (K == 0) return One();
			Polynomial inv = q.precomputeRevInverse(std::max(size() - qn + 1, qn));
			Polynomial p = this->computeRemainderPrecomputedRevInverse(q, inv);
			int l = 0;
			while ((K >> l) > 1) ++ l;
			Polynomial res = p;
			for (-- l; l >= 0; -- l) {
				res *= res;
				res = res.computeRemainderPrecomputedRevInverse(q, inv);
				if (K >> l & 1) {
					res *= p;
					res = res.computeRemainderPrecomputedRevInverse(q, inv);
				}
			}
			return res;
		}

		Polynomial reverse(int n) {
			assert(size() <= n);
			Polynomial r; r.resize(n);
			for (int i = 0; i < n; ++ i)
				r.set(n - 1 - i, get(i));
			return r;
		}

		Polynomial operator%(const Polynomial &that) const {
			if (size() < that.size()) return *this;
			auto inv = that.precomputeRevInverse(size() - that.size() + 1);
			return computeRemainderPrecomputedRevInverse(that, inv);
		}

		void multipointEvaluation(const vector<R> &points, vector<R> &res) const {
			int N = 1;
			while (N < (int)points.size()) N *= 2;
			vector<Polynomial> prods(N * 2);
			for (int i = 0; i < N; ++ i) {
				if (i < (int)points.size()) {
					prods[N + i] = Polynomial(ZeroR() - points[i], OneR());
				} else {
					prods[N + i] = Polynomial::One();
				}
			}
			for (int i = N - 1; i >= 1; -- i) {
				const auto &p = prods[i * 2 + 0];
				const auto &q = prods[i * 2 + 1];
				prods[i] = p * q;
			}
			function<void(int, const Polynomial&)> rec = [&](int i, const Polynomial &p) {
				const Polynomial &m = prods[i];
				if (m.size() <= 1) return;
				if (i >= N) {
					assert(i - N < (int)points.size());
					res[i - N] = p.evaluate(points[i - N]);
					return;
				}
				if (p.size() < m.size()) {
					rec(i * 2 + 0, p);
					rec(i * 2 + 1, p);
				} else {
					auto np = p % m;
					rec(i * 2 + 0, np);
					rec(i * 2 + 1, np);
				}
			};
			res.resize(points.size());
			rec(1, *this);
		}

		static int MULTIPRIME_FFT_THRESHOLD;

	private:
		static NumberTable _numberTable;

		class WorkSpaceStack;

		static void _fill_zero(R *res, int n);
		static void _copy(R *res, const R *p, int n);
		static void _negate(R *res, const R *p, int n);

		static void _add(R *p, const R *q, int n);
		static void _add(R *res, const R *p, int pn, const R *q, int qn);
		static void _subtract(R *p, const R *q, int n);
		static void _subtract(R *res, const R *p, int pn, const R *q, int qn);

		static void _multiply_select_method(R *res, const R *p, int pn, const R *q, int qn);
		static void _square_select_method(R *res, const R *p, int pn);

		static void _multiply_1(R *p, const R *q, int n, R c0);
		static void _multiply_1(R *p, int n, R c0);

		static void _multiply_power_of_two(R *res, const R *p, int n, int k);
		static void _divide_power_of_two(R *res, const R *p, int n, int k);

		static void _schoolbook_multiplication(R *res, const R *p, int pn, const R *q, int qn);

		static void _direct_fft(R *res, const R *p, int pn, const R *q, int qn);

		static void _reverse(R *res, const R *p, int pn);
		static void _inverse_power_series(R *res, int resn, const R *p, int pn);
		static void _precompute_reverse_inverse(R *res, int resn, const R *p, int pn);
		static void _divide_precomputed_inverse(R *res, int resn, const R *revp, int pn, const R *inv);
		static void _divide_remainder_precomputed_inverse(R *quot, R *rem, const R *p, int pn, const R *q, int qn, const R *inv);
	};
	int Polynomial::MULTIPRIME_FFT_THRESHOLD = 8;
	Polynomial::NumberTable Polynomial::_numberTable;

	void Polynomial::_fill_zero(R *res, int n) {
		for (int i = 0; i < n; ++ i)
			res[i] = ZeroR();
	}

	void Polynomial::_copy(R *res, const R *p, int n) {
		for (int i = 0; i < n; ++ i)
			res[i] = p[i];
	}

	void Polynomial::_negate(R *res, const R *p, int n) {
		for (int i = 0; i < n; ++ i)
			res[i] = -p[i];
	}

	void Polynomial::_add(R *res, const R *p, int pn, const R *q, int qn) {
		for (int i = 0; i < qn; ++ i)
			res[i] = p[i] + q[i];
		_copy(res + qn, p + qn, pn - qn);
	}

	void Polynomial::_subtract(R *res, const R *p, int pn, const R *q, int qn) {
		for (int i = 0; i < qn; ++ i)
			res[i] = p[i] - q[i];
		_copy(res + qn, p + qn, pn - qn);
	}

	void Polynomial::_add(R *p, const R *q, int n) {
		_add(p, p, n, q, n);
	}

	void Polynomial::_subtract(R *p, const R *q, int n) {
		_subtract(p, p, n, q, n);
	}

	void Polynomial::_multiply_1(R *res, const R *p, int n, R c0) {
		for (int i = 0; i < n; ++ i)
			res[i] = p[i] * c0;
	}

	void Polynomial::_multiply_1(R *p, int n, R c0) {
		_multiply_1(p, p, n, c0);
	}

	void Polynomial::_multiply_power_of_two(R *res, const R *p, int n, int k) {
		assert(0 < k && k < 31);
		R mul = R(1 << k);
		_multiply_1(res, p, n, mul);
	}

	void Polynomial::_divide_power_of_two(R *res, const R *p, int n, int k) {
		assert(0 < k && k < 31);
		static const R Inv2 = R(2).inverse();
		R inv = k == 1 ? Inv2 : R(1 << k).inverse();
		_multiply_1(res, p, n, inv);
	}


	void Polynomial::_multiply_select_method(R *res, const R *p, int pn, const R *q, int qn) {
		if (pn < qn) std::swap(p, q), std::swap(pn, qn);
		assert(res != p && res != q && pn >= qn && qn > 0);
		int rn = pn + qn - 1;
		if (qn == 1) {
			_multiply_1(res, p, pn, q[0]);
		} else if (qn < MULTIPRIME_FFT_THRESHOLD) {
			_schoolbook_multiplication(res, p, pn, q, qn);
		} else {
			_direct_fft(res, p, pn, q, qn);
		}
	}

	void Polynomial::_square_select_method(R *res, const R *p, int pn) {
		_multiply_select_method(res, p, pn, p, pn);
	}

	void Polynomial::_schoolbook_multiplication(R *res, const R *p, int pn, const R *q, int qn) {
		if (qn == 1) {
			_multiply_1(res, p, pn, q[0]);
			return;
		}
		assert(res != p && res != q && pn >= qn && qn > 0);

		_fill_zero(res, pn + qn - 1);
		for (int i = 0; i < pn; ++ i)
			for (int j = 0; j < qn; ++ j)
				res[i + j] += p[i] * q[j];
	}

	void Polynomial::_direct_fft(R *res, const R *p, int pn, const R *q, int qn) {
		int resn = pn + qn - 1;

		int n = 0;
		while ((1 << n) < resn || (1 << n) < pn + qn - 1) ++ n;

		unique_ptr<R[]> work(new R[size_t(2) << n]);
		R *f = work.get(), *g = f + (size_t(1) << n);
		_fill_zero(f, 1 << n);
		_fill_zero(g, 1 << n);
		_copy(f, p, pn);
		_copy(g, q, qn);
		fft::convolute(reinterpret_cast<R::ModNum*>(f), reinterpret_cast<R::ModNum*>(g), n, R::get_mod_info());
		_copy(res, f, resn);
	}

	void Polynomial::_reverse(R *res, const R *p, int pn) {
		if (res == p) {
			std::reverse(res, res + pn);
		} else {
			for (int i = 0; i < pn; ++ i)
				res[pn - 1 - i] = p[i];
		}
	}

	void Polynomial::_inverse_power_series(R *res, int resn, const R *p, int pn) {
		if (resn == 0) return;
		assert(res != p);
		assert(pn > 0);
		assert(!IsZeroR(p[0]));
		if (p[0] != OneR()) {
			unique_ptr<R[]> tmpp(new R[pn]);
			R ic0 = p[0].inverse();
			_multiply_1(tmpp.get(), p, pn, ic0);
			_inverse_power_series(res, resn, tmpp.get(), pn);
			_multiply_1(res, resn, ic0);
			return;
		}
		unique_ptr<R[]> ws(new R[resn * 4]);
		R *tmp1 = ws.get(), *tmp2 = tmp1 + resn * 2;
		_fill_zero(res, resn);
		res[0] = p[0];
		int curn = 1;
		while (curn < resn) {
			int nextn = std::min(resn, curn * 2);
			_square_select_method(tmp1, res, curn);
			_multiply_select_method(tmp2, tmp1, std::min(nextn, curn * 2 - 1), p, std::min(nextn, pn));
			_multiply_power_of_two(res, res, curn, 1);
			_subtract(res, tmp2, nextn);
			curn = nextn;
		}
	}

	void Polynomial::_precompute_reverse_inverse(R *res, int resn, const R *p, int pn) {
		unique_ptr<R[]> ws(new R[pn]);
		R *tmp = ws.get();
		_reverse(tmp, p, pn);
		_inverse_power_series(res, resn, tmp, pn);
	}

	void Polynomial::_divide_precomputed_inverse(R *res, int resn, const R *revp, int pn, const R *inv) {
		unique_ptr<R[]> ws(new R[pn + resn]);
		R *tmp = ws.get();
		_multiply_select_method(tmp, revp, pn, inv, resn);
		_reverse(res, tmp, resn);
	}

	void Polynomial::_divide_remainder_precomputed_inverse(R *quot, R *rem, const R *p, int pn, const R *q, int qn, const R *inv) {
		if (pn < qn) {
			_copy(rem, p, pn);
			_fill_zero(rem + pn, qn - 1 - pn);
			return;
		}
		assert(qn > 0);
		assert(q[qn - 1] == OneR());
		if (qn == 1) return;
		int quotn = pn - qn + 1;
		int rn = qn - 1, tn = std::min(quotn, rn), un = tn + rn;
		unique_ptr<R[]> ws(new R[pn + un + (quot != NULL ? 0 : quotn)]);
		R *revp = ws.get(), *quotmul = revp + pn;
		if (quot == NULL) quot = quotmul + un;
		_reverse(revp, p, pn);
		_divide_precomputed_inverse(quot, quotn, revp, pn, inv);
		_multiply_select_method(quotmul, q, rn, quot, tn);
		_subtract(rem, p, rn, quotmul, rn);
	}
}


vector<int> t_parent;
vector<int> t_ord;

void tree_getorder(const vector<vector<int>> &g, int root) {
	int n = (int)g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for (int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

template<typename Sum, typename Combine, typename Calc>
void freeTreeDP(const vector<int> &t_ord, const vector<int> &t_parent, vector<Sum> &downsum, vector<Sum> &upsum, Sum identity, Combine combine, Calc calc) {
	int n = (int)t_ord.size();
	vector<int> children(n, 0), childid(n, -1);
	for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
		int i = t_ord[ix], p = t_parent[i];
		childid[i] = children[p] ++;
	}
	vector<vector<Sum>> prefix(n), suffix(n);
	for (int i = 0; i < n; ++ i) {
		prefix[i].assign(children[i] + 1, identity);
		suffix[i].assign(children[i] + 1, identity);
	}
	downsum.assign(n, identity);
	upsum.assign(n, identity);
	for (int ix = (int)t_ord.size() - 1; ix >= 0; -- ix) {
		int i = t_ord[ix], p = t_parent[i];
		for (int j = 0; j < children[i]; ++ j)
			prefix[i][j + 1] = combine(prefix[i][j], prefix[i][j + 1]);
		for (int j = children[i]; j > 0; -- j)
			suffix[i][j - 1] = combine(suffix[i][j - 1], suffix[i][j]);
		if (p != -1) {
			downsum[i] = calc(p, i, suffix[i][0]);
			prefix[p][childid[i] + 1] = downsum[i];
			suffix[p][childid[i]] = downsum[i];
		}
	}
	downsum[t_ord[0]] = suffix[t_ord[0]][0];
	for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
		int i = t_ord[ix], p = t_parent[i];
		Sum sum = suffix[p][childid[i] + 1];
		sum = combine(sum, upsum[p]);
		sum = combine(sum, prefix[p][childid[i]]);
		upsum[i] = calc(i, p, sum);
	}
}

vector<mint> fact, factinv;
void nCr_computeFactinv(int N) {
	N = min(N, (int)mint::getMod() - 1);
	fact.resize(N + 1); factinv.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++ i) fact[i] = fact[i - 1] * i;
	factinv[N] = fact[N].inverse();
	for (int i = N; i >= 1; i --) factinv[i - 1] = factinv[i] * i;
}
bool naivegetpath(int i, int p, int t, const vector<vector<int>> &g, vector<int> &path) {
	bool r = false;
	if (i == t) {
		r = true;
	} else {
		for (int j : g[i]) if (j != p)
			r = r || naivegetpath(j, i, t, g, path);
	}
	if (r)
		path.push_back(i);
	return r;
}
int main() {
	using mint = ModInt;
	using Polynomial = mod_polynomial::Polynomial;
	mint::set_fft_mod(998244353, -1, 31, 23);
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		nCr_computeFactinv(k);
		if (k == 1) {
			mint ans = mint(n) * (n - 1) / 2;
			printf("%d\n", ans.get());
			continue;
		}
		tree_getorder(g, 0);
		vector<int> subtsize(t_ord.size(), 1);
		for (int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}
		auto makeProduct = [k](auto makeProduct, int L, int R, const vector<mint> &xs) -> Polynomial {
			if (L + 1 == R) {
				Polynomial p;
				p.resize(2);
				p.set(0, 1);
				p.set(1, xs[L]);
				return p;
			}
			int mid = (L + R) / 2;
			auto p = makeProduct(makeProduct, L, mid, xs);
			auto q = makeProduct(makeProduct, mid, R, xs);
			auto r = p * q;
			return r;
		};
		vector<mint> up(n), down(n);
		for (int ix = 0; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			vector<mint> xs;
			if (p != -1)
				xs.push_back(n - subtsize[i]);
			for (int j : g[i]) if (j != p)
				xs.push_back(subtsize[j]);
			if (xs.empty()) continue;
			auto poly = makeProduct(makeProduct, 0, (int)xs.size(), xs);
			int d = min(k, poly.degree());
			Polynomial comb;
			comb.resize(d + 1);
			for (int i = 0; i <= d; ++ i)
				comb.set(i, fact[k] * factinv[k - d + i]);
			poly *= comb;
			poly.resize(d + 1);
			poly = poly.reverse(d + 1);
			vector<mint> points = xs;
			for (auto &x : points) x = -x;
			vector<mint> evaluated;
			poly.multipointEvaluation(points, evaluated);
			int t = 0;
			if (p != -1)
				down[i] = evaluated[t ++];
			for (int j : g[i]) if (j != p)
				up[j] = evaluated[t ++];
		}
		vector<mint> downSum = down;
		for (int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			downSum[p] += downSum[i];
		}
		mint ans;
		for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			mint x = up[i], y = downSum[i];
			int a = subtsize[i];
		}
		for (int ix = 0; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			mint sum;
			for (int j : g[i]) if (j != p) {
				mint x = downSum[j];
				ans += up[j] * x;
				ans += sum * x;
				sum += x;
			}
		}
		printf("%d\n", ans.get());
	}
}