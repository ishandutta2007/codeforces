// Son
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

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


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

str A[N];

int n, m;
vector<int> G[N];
int cur[N];
void Add(int u, int v){
	G[u].pb(v);
	G[v].pb(u);
}

int mk[N];
vector<int> V;
void DFS(int u){
	mk[u]= 1;
	V.pb(u);
	for(auto adj : G[u]) if(!mk[adj]) DFS(adj);
}

void Reset(){
	for(int i = 0; i < N; i++) G[i].clear();
	memset(mk, 0, sizeof mk);
	memset(cur, 0, sizeof cur);
	// memset(mk, 0, sizeof mk);
}

mi Solve(int x){
	Reset();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] == '?') Add(i, j + n);
			else {
				cur[i] ^= (A[i][j] - '0');
				cur[n + j] ^= (A[i][j] - '0');
			}
		}
	}
	mi ans = 1;
	for(int i = 0; i < n + m; i++){
		if(mk[i]) continue;
		V.clear();
		DFS(i);
		int d = 0;
		for(auto u : V) if(cur[u] != x) d++;
		if(d % 2 == 1) return mi(0);
		int sd = 0;
		for(auto u : V) sd += G[u].size();
		int e = sd / 2;
		int ver = V.size();
		ans *= bin_pow(mi(2), e - (ver - 1));
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int k = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		for(auto c : A[i]) k += (c == '?');
	}
	if((n % 2 == 0) && (m % 2 == 0)){
		cout << bin_pow(mi(2), k) << '\n';
		return 0;
	}
	if((n % 2 == 0) && (m % 2 == 1)){
		mi c0 = 1;
		mi c1 = 1;
		for(int i = 0; i < n; i++){
			int sm = 0, c = 0;
			for(int j = 0; j < m; j++){
				if(A[i][j] == '?') c++;
				else sm ^= (A[i][j]-'0');
			}
			if(c) c1 *= bin_pow(mi(2), c - 1), c0 *= bin_pow(mi(2), c - 1);
			else {
				if(sm == 0) c1 = 0;
				else c0 = 0;
			}
		}
		cout << c0 + c1 << '\n';
		return 0;
	}

	if((n % 2 == 1) && (m % 2 == 0)){
		mi c0 = 1;
		mi c1 = 1;
		for(int i = 0; i < m; i++){
			int sm = 0, c = 0;
			for(int j = 0; j < n; j++){
				if(A[j][i] == '?') c++;
				else sm ^= (A[j][i]-'0');
			}
			if(c) c1 *= bin_pow(mi(2), c - 1), c0 *= bin_pow(mi(2), c - 1);
			else {
				if(sm == 0) c1 = 0;
				else c0 = 0;
			}
		}
		cout << c0 + c1 << '\n';
		return 0;
	}
	assert(((n * m) % 2) == 1);
	cout << Solve(0) + Solve(1) << '\n';
	return 0;
}