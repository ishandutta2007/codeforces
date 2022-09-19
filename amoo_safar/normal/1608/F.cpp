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
const int N = 2e3 + 10;
const int K = 105;
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
	constexpr int MintMod = 998244353;
	using mi = Mint<integral_constant<decay<decltype(MintMod)>::type, MintMod>>;
};

using namespace ModularInt;

int k;
mi dp[2][N][K], tmp[N][K];
int b[N];
inline int Get(int i, int mx){
	int res = mx - b[i] + 50;
	return res;
}
inline int Undo(int i, int mx){
	return mx - 50 + b[i];
}

mi f[N], iv[N];

mi nCr(int n, int r){
	if(r < 0 || n < 0 || n < r) return 0;
	return f[n] * iv[r] * iv[n - r];
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = i * f[i - 1];
	for(int i = 0; i < N; i++)iv[i] = inverse(f[i]);

	int n;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> b[i];
	if(abs(b[0]) <= k) dp[0][1][Get(0, 0)] = 1;
	if(abs(b[0]-1)<=k) dp[0][1][Get(0, 1)] = 1;

	int nw, nx;
	for(int i = 1; i < n; i++){
		for(int cnt = 1; cnt <= i + 1; cnt ++){
			for(int mex = 0; mex < K - 1; mex ++){
				if(dp[0][cnt][mex] == 0) continue;
				nw = Undo(i - 1, mex);
				nx = Get(i, nw);
				if(abs(nw - b[i]) <= k){
					dp[1][cnt][nx] += cnt * dp[0][cnt][mex];
					dp[1][cnt + 1][nx] += dp[0][cnt][mex];
				}
				//////
				int delta = 1;
				if(nw + delta > b[i] + k) continue;
				if(nw + delta < b[i] - k)
					delta = b[i] - k - nw;
				int st = cnt - nw;
				mi z = nCr(st, delta - 1) * f[delta - 1];
				tmp[cnt + 1][Get(i, nw + delta)] += dp[0][cnt][mex] * z; 
			}
		}
		// tmp ps
		for(int cnt = 1; cnt <= i + 1; cnt ++){
			for(int mex = 0; mex < K - 1; mex ++){
				nw = Undo(i, mex);
				if(abs((nw + 1) - b[i]) > k) continue;
				
				nx = Get(i, nw);
				tmp[cnt][nx + 1] += (cnt - nw) * tmp[cnt][mex];
			}
		}
		for(int cnt = 1; cnt <= i + 1; cnt ++){
			for(int mex = 0; mex < K - 1; mex ++){
				// dp[1][cnt][mex] = 0;
				// dp[0][cnt][mex] = 0;
				nw = Undo(i, mex);
				if(abs(nw - b[i]) > k){
					dp[1][cnt][mex] = 0;
					dp[0][cnt][mex] = 0;
					tmp[cnt][mex] = 0;
					continue;
				}
				dp[0][cnt][mex] = tmp[cnt][mex] + dp[1][cnt][mex];
				dp[1][cnt][mex] = 0;
				tmp[cnt][mex] = 0;
				
			}
		}		
	}
	mi ans = 0;
	for(int cnt = 1; cnt <= n; cnt ++){
		for(int mex = 0; mex < K - 1; mex ++){
			nw = Undo(n - 1, mex);
			if(dp[0][cnt][mex] == 0) continue;
			if(abs(nw - b[n - 1]) > k) continue;
			if(cnt >= nw){
				int tot = n - nw;
				int rem = cnt - nw;
				ans += f[rem] * dp[0][cnt][mex] * nCr(tot, rem);
			}
		}
	}
	cout << ans << '\n';		
	return 0;
}