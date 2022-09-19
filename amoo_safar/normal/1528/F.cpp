// Conor Gallagher
#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef string str;

const int N = 1e5 + 10;

namespace ModularInt {
	template<typename T>
	T inverse(T a, T pr){
		T u = 1, v = 0;
		while(a != 0){
			T dv = pr / a;
			pr -= dv * a; v -= dv * u;
			swap(a, pr); swap(u, v);
		}
		assert(pr == 1); // gcd(a, pr) != 1;
		return v;
	}

	template<typename ModT>
	class Mint {
	public:
		using T = typename decay<decltype(ModT::value)>::type;
		T val;
	

		Mint() : val() {}
		template<typename Q>
		Mint(const Q& x){ val = normalize(x); }
		Mint(const Mint& x) { val = x.val; }

		template <typename U>
		explicit operator U() const { return static_cast<U>(val); }

		constexpr static T _Mod() { return ModT::value; }

		friend Mint inverse(Mint x){ return inverse(x.val, _Mod()); }

		template<typename Q>
		static T normalize(const Q& x){
			T val;
			if(-_Mod() <= x && x < _Mod()) val = x;
			else val = x % _Mod();
			if(val < 0) val += _Mod();
			return val;
		}
		
		template<typename Q>
		Mint& operator=(const Q& x){ val = normalize(x); return *this; }

		Mint& operator +=(const Mint& other){ if(_Mod() <= (val += other.val)) val -= _Mod(); return *this; }
		Mint& operator -=(const Mint& other){ if((val -= other.val) < 0) val += _Mod(); return *this; }
		template<typename Q> Mint& operator +=(const Q& other){ return (*this) += Mint(other); };
		template<typename Q> Mint& operator -=(const Q& other){ return (*this) -= Mint(other); };
		Mint& operator ++(){ return (*this) += 1; }
		Mint& operator --(){ return (*this) -= 1; }
		Mint operator ++(int){ Mint res(*this); (*this) += 1; return res; }
		Mint operator --(int){ Mint res(*this); (*this) -= 1; return res; }
		Mint operator +(){ Mint res(val); return res; }
		Mint operator -(){ Mint res(-val); return res; }

		Mint& operator *=(const Mint& other){ val = (1ll * val * other.val) % _Mod(); return *this; }
		Mint& operator /=(const Mint& other){ return (*this) *= inverse(other); }
		template<typename Q> Mint& operator *=(const Q& other){ return (*this) *= Mint(other); }
		template<typename Q> Mint& operator /=(const Q& other){ return (*this) /= Mint(other); }
	};


	template<typename T> Mint<T> operator +(const Mint<T>& lhs, const Mint<T>& rhs){ return Mint<T>(lhs) += rhs; }
	template<typename T, typename Q>  Mint<T> operator +(const Q& lhs, const Mint<T>& rhs){ return Mint<T>(lhs) += rhs; }
	template<typename T, typename Q>  Mint<T> operator +(const Mint<T>& lhs, const Q& rhs){ return Mint<T>(lhs) += rhs; }

	template<typename T> Mint<T> operator -(const Mint<T>& lhs, const Mint<T>& rhs){ return Mint<T>(lhs) -= rhs; }
	template<typename T, typename Q>  Mint<T> operator -(const Q& lhs, const Mint<T>& rhs){ return Mint<T>(lhs) -= rhs; }
	template<typename T, typename Q>  Mint<T> operator -(const Mint<T>& lhs, const Q& rhs){ return Mint<T>(lhs) -= rhs; }

	template<typename T> Mint<T> operator *(const Mint<T>& lhs, const Mint<T>& rhs){ return Mint<T>(lhs) *= rhs; }
	template<typename T, typename Q>  Mint<T> operator *(const Q& lhs, const Mint<T>& rhs){ return Mint<T>(lhs) *= rhs; }
	template<typename T, typename Q>  Mint<T> operator *(const Mint<T>& lhs, const Q& rhs){ return Mint<T>(lhs) *= rhs; }

	template<typename T> Mint<T> operator /(const Mint<T>& lhs, const Mint<T>& rhs){ return Mint<T>(lhs) /= rhs; }
	template<typename T, typename Q>  Mint<T> operator /(const Q& lhs, const Mint<T>& rhs){ return Mint<T>(lhs) /= rhs; }
	template<typename T, typename Q>  Mint<T> operator /(const Mint<T>& lhs, const Q& rhs){ return Mint<T>(lhs) /= rhs; }

	template<typename T> bool operator ==(const Mint<T>& lhs, const Mint<T>& rhs){ return lhs.val == rhs.val; }
	template<typename T, typename Q>  bool operator ==(const Q& lhs, const Mint<T>& rhs){ return Mint<T>(lhs) == rhs; }
	template<typename T, typename Q>  bool operator ==(const Mint<T>& lhs, const Q& rhs){ return lhs == Mint<T>(rhs); }

	template<typename T> bool operator !=(const Mint<T>& lhs, const Mint<T>& rhs){ return !(lhs == rhs); }
	template<typename T, typename Q>  bool operator !=(const Q& lhs, const Mint<T>& rhs){ return !(lhs == rhs); }
	template<typename T, typename Q>  bool operator !=(const Mint<T>& lhs, const Q& rhs){ return !(lhs == rhs); }

	template<typename T, typename IO>
	IO& operator <<(IO& ostream, const Mint<T>& _x){
		return ostream << _x.val;
	}
	template<typename T, typename IO>
	IO& operator >>(IO& istream, Mint<T>& _x){
		return istream >> _x.val;
	}

	template<typename T, typename Q>
	Mint<T> bin_pow(const Mint<T>& base, Q power){
		assert(0 <= power);
		Mint<T> res = 1, pw = base;
		for(Q j = 1; j <= power; j <<= 1, pw *= pw)
			if(j & power)
				res *= pw;
		return res;
	}

	// Dynamic
	
	/*
	using ModType = int;
	struct VarMod { static ModType value; };
	ModType VarMod::value;
	ModType& MintMod = VarMod::value;
	using mi = Mint<VarMod>;
	*/

	// Static
	constexpr int MintMod = 998244353;
	using mi = Mint<integral_constant<decay<decltype(MintMod)>::type, MintMod>>;
};
using namespace ModularInt;
namespace MintFFT {
	const int _Log = 18;
	const int _N = (1 << _Log);
	const mi invN = inverse(mi(_N));
	const mi _root = 3;
	
	bool _init = false;
	mi pw[2][_N];
	
	inline void Init(){
		if(_init) return ;
		_init = true;
		pw[0][0] = 1; pw[1][0] = 1;
		pw[0][1] = bin_pow(_root, (_root._Mod() - 1) / _N);
		for(int i = 2; i < _N; i++)
			pw[0][i] = pw[0][i - 1] * pw[0][1];
		for(int i = 1; i < _N; i++)
			pw[1][i] = pw[0][_N - i];
	}
	void NTT(vector<mi>& arr, bool inv){
		Init();
		for(int i = 1, rv = 0; i < _N; i++){
			int bt = _N >> 1;
			for(rv ^= bt; (rv & bt) == 0; rv ^= (bt >>= 1) );
			if(rv < i)
				swap(arr[rv], arr[i]);
		}
		for(int len = 2, _lg = 1; len <= _N; len <<= 1, _lg ++){
			for(int st = 0; st < _N; st += len){
				for(int j = 0; j < (len >> 1); j++){
					mi &A = arr[st + j], &B = arr[st + j + (len >> 1)], C = pw[inv][(_N >> _lg) * j] * B;
					B = A - C;
					A = A + C;
				}
			}
		}
		if(inv){
			for(int i = 0; i < _N; i++)
				arr[i] *= invN;
		}
	}
};

using MintFFT::NTT;
using MintFFT::_N;

mi f[N], iv[N];
mi nCr(int n, int r){
	if(r < 0 || n < 0 || n < r) return 0;
	return f[n] * iv[r] * iv[n - r];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = i * f[i - 1];
	iv[N - 1] = inverse(f[N - 1]);
	for(int i = N - 2; ~i; i--)iv[i]= iv[i + 1] * (i + 1);
	
	int n, k;
	cin >> n >> k;

	vector<mi> B(_N, 0), P(_N, 0);
	for(int i = 0; i <= k; i++) B[i] = (i & 1 ? -1 : 1) * iv[i];
	for(int i = 0; i <= k; i++) P[i] = bin_pow(mi(i), k) * iv[i];
	NTT(B, false); NTT(P, false);
	for(int i = 0; i < _N; i++) B[i] *= P[i];
	NTT(B, true);

	mi ans = 0;
	mi C = 1;
	for(int d = 1; d <= min(n, k); d++){
		C *= (n - d + 1);
		C /= d;
		ans += C * f[d] * B[d] * bin_pow(mi(n + 1), n + 1 - d);
	}
	cout << ans / (n + 1) << '\n';
	return 0;
}