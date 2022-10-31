#include "bits/stdc++.h"
#include <emmintrin.h>
using namespace std;

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


	enum { MULTIPRIME_NUM = 2 };

	static const ModInfo fft_prime_mod0 = ModInfo::make_support_fft(998244353, -1, 31, 23);
	static const ModInfo fft_prime_mod1 = ModInfo::make_support_fft(897581057, -1, 45, 23);
	const ModInfo * const fft_prime_mods[MULTIPRIME_NUM] = { &fft_prime_mod0, &fft_prime_mod1 };

	void multiprime_compose_64(uint64_t *res, const ModNum *f[MULTIPRIME_NUM], int N, const ModInfo * const mods[MULTIPRIME_NUM]) {
		const auto f0 = f[0], f1 = f[1], f2 = f[2];
		const auto &mod0 = *mods[0], &mod1 = *mods[1];
		const auto P0 = mod0.getP(), P1 = mod1.getP();
		const auto t1 = mod1.inverse(mod1.to_alt(P0));

		for (int i = 0; i < N; ++ i) {
			const auto a0 = mod0.from_alt(f0[i]), a1 = mod1.from_alt(f1[i]);
			const auto d1 = mod1.sub(mod1.to_alt(a1), mod1.to_alt(a0));
			const auto h1 = mod1.from_alt(mod1.mul(d1, t1));
			const auto a01 = a0 + (uint64_t)P0 * h1;
			res[i] = a01;
		}
	}

	void multiprime_decompose_64(ModNum *res[MULTIPRIME_NUM], const uint32_t *f, int N, const ModInfo * const mods[MULTIPRIME_NUM]) {
		for (int i = 0; i < N; ++ i) {
			auto a = f[i];
			for (int k = 0; k < MULTIPRIME_NUM; ++ k)
				res[k][i] = mods[k]->to_alt(f[i]);
		}
	}

	void multiprime_convolute_64(uint64_t *res, int resN, const uint32_t *f, int fN, const uint32_t *g, int gN, int n) {
		int N = 1 << n;
		assert(fN <= N && gN <= N && resN <= N);
		//implicit zero-fill
		unique_ptr<ModNum[]> workspace(new ModNum[N * MULTIPRIME_NUM * 2]);
		ModNum *fs[MULTIPRIME_NUM], *gs[MULTIPRIME_NUM];
		for (int k = 0; k < MULTIPRIME_NUM; ++ k) {
			fs[k] = workspace.get() + (k * 2 + 0) * N;
			gs[k] = workspace.get() + (k * 2 + 1) * N;
		}
		multiprime_decompose_64(fs, f, fN, fft_prime_mods);
		multiprime_decompose_64(gs, g, gN, fft_prime_mods);
		for (int k = 0; k < MULTIPRIME_NUM; ++ k)
			convolute(fs[k], gs[k], n, *fft_prime_mods[k]);
		multiprime_compose_64(res, const_cast<const ModNum **>(fs), resN, fft_prime_mods);
	}
}

int main() {
	int n; int x;
	while (~scanf("%d%d", &n, &x)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> sum(n + 1);
		for (int i = 0; i < n; ++ i)
			sum[i + 1] = sum[i] + (a[i] < x);

		vector<uint32_t> p(n + 1), q(n + 1);
		vector<uint64_t> prod(n * 2 + 1);
		for (int i = 0; i <= n; ++ i) {
			++ p[sum[i]];
			++ q[n - sum[i]];
		}
		int logn = 1;
		for (; 1 << logn < n * 2 + 1; ++ logn);
		fft::multiprime_convolute_64(prod.data(), n * 2 + 1, p.data(), n + 1, q.data(), n + 1, logn);
		for (int i = 0; i <= n; ++ i) {
			long long ans = prod[n + i];
			if (i == 0) ans = (ans - (n + 1)) / 2;
			printf("%lld%c", ans, i == n ? '\n' : ' ');
		}
	}
}