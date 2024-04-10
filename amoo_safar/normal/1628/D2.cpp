#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 1e6 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;


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
	constexpr int MintMod = 1'000'000'007;
	using mi = Mint<integral_constant<decay<decltype(MintMod)>::type, MintMod>>;
};

using namespace ModularInt;


// mi dp[N][N];

mi f[N];
mi iv[N];
mi p2[N];

mi nCr(int n, int r){
	if(n < 0 || r < 0 || n < r) return 0;
	return f[n] * iv[r] * iv[n - r];
}

int Main(){
	int n, m;
	mi k;
	cin >> n >> m >> k;
	mi ans = 0;
	for(int i = m; i >= 1; i--){
		ans += (i - (mi(i - 1) * p2[1])) * nCr(n - i, n - m) * p2[n - i];
	}
	cout << ans * k << '\n';
	return 0;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	p2[0] = 1;
	for(int i = 1; i < N; i++) f[i] = f[i - 1] * i, p2[i] = p2[i - 1] * 2;
	for(int i = 0; i < N; i++) iv[i] = inverse(f[i]), p2[i] = inverse(p2[i]);

		// debug(nCr(5, 2));
	// mi iv2 = mi(1) / mi(2); 
	// for(int i = 1; i < N; i++){
	// 	dp[i][0] = 0;
	// 	dp[i][i] = i;
	// 	for(int j = 1; j < i; j++)
	// 		dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) * iv2;
	// }
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}