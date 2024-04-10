// vaziat meshki-ghermeze !
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

const ll Mod = 1000000007LL;
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


template<typename T, int _Mod>
struct Mint {
	T val;
	Mint() : val(0) {}

	template<typename Q>
	T normalize(const Q& x){
		T val;
		if(-_Mod <= x && x < _Mod) val = x;
		else val = x % _Mod;
		if(val < 0) val += _Mod;
		return val;
	}
	Mint(const Mint& x) { val = x.val; }
	template<typename Q>
	Mint(const Q& x){ val = normalize(x); }
	template<typename Q>
	Mint& operator=(const Q& x){ val = normalize(x); return *this; }

	template<typename Q>
	friend Mint bin_pow(Mint& base, Q power){
		assert(0 <= power);
		Mint res = 1, pw = base;
		for(Q j = 1; j <= power; j <<= 1, pw *= pw)
			if(j & power)
				res *= pw;
		return res;
	}
	friend Mint inverse(Mint x){ return bin_pow(x, _Mod - 2); }

	Mint& operator +=(const Mint& other){ if(_Mod <= (val += other.val)) val -= _Mod; return *this; }
	Mint& operator -=(const Mint& other){ if((val -= other.val) < 0) val += _Mod; return *this; }
	template<typename Q> Mint& operator +=(const Q& other){ return (*this) += Mint(other); };
	template<typename Q> Mint& operator -=(const Q& other){ return (*this) -= Mint(other); };
	Mint& operator ++(){ return (*this) += 1; }
	Mint& operator --(){ return (*this) -= 1; }
	Mint operator ++(int){ Mint res(*this); (*this) += 1; return res; }
	Mint operator --(int){ Mint res(*this); (*this) -= 1; return res; }
	Mint operator +(){ Mint res(val); return res; }
	Mint operator -(){ Mint res(-val); return res; }

	Mint& operator *=(const Mint& other){ val = (1ll * val * other.val) % _Mod; return *this; }
	Mint& operator /=(const Mint& other){ return (*this) *= inverse(other); }
	template<typename Q> Mint& operator *=(const Q& other){ return (*this) *= Mint(other); }
	template<typename Q> Mint& operator /=(const Q& other){ return (*this) /= Mint(other); }

	friend Mint operator +(const Mint& lhs, const Mint& rhs){ return Mint(lhs) += rhs; }
	template<typename Q> friend Mint operator +(const Q& lhs, const Mint& rhs){ return Mint(lhs) += rhs; }
	template<typename Q> friend Mint operator +(const Mint& lhs, const Q& rhs){ return Mint(lhs) += rhs; }

	friend Mint operator -(const Mint& lhs, const Mint& rhs){ return Mint(lhs) -= rhs; }
	template<typename Q> friend Mint operator -(const Q& lhs, const Mint& rhs){ return Mint(lhs) -= rhs; }
	template<typename Q> friend Mint operator -(const Mint& lhs, const Q& rhs){ return Mint(lhs) -= rhs; }

	friend Mint operator *(const Mint& lhs, const Mint& rhs){ return Mint(lhs) *= rhs; }
	template<typename Q> friend Mint operator *(const Q& lhs, const Mint& rhs){ return Mint(lhs) *= rhs; }
	template<typename Q> friend Mint operator *(const Mint& lhs, const Q& rhs){ return Mint(lhs) *= rhs; }

	friend Mint operator /(const Mint& lhs, const Mint& rhs){ return Mint(lhs) /= rhs; }
	template<typename Q> friend Mint operator /(const Q& lhs, const Mint& rhs){ return Mint(lhs) /= rhs; }
	template<typename Q> friend Mint operator /(const Mint& lhs, const Q& rhs){ return Mint(lhs) /= rhs; }

	friend bool operator ==(const Mint& lhs, const Mint& rhs){ return lhs.val == rhs.val; }
	template<typename Q> friend bool operator ==(const Q& lhs, const Mint& rhs){ return Mint(lhs) == rhs; }
	template<typename Q> friend bool operator ==(const Mint& lhs, const Q& rhs){ return lhs == Mint(rhs); }

	friend bool operator !=(const Mint& lhs, const Mint& rhs){ return !(lhs == rhs); }
	template<typename Q> friend bool operator !=(const Q& lhs, const Mint& rhs){ return !(lhs == rhs); }
	template<typename Q> friend bool operator !=(const Mint& lhs, const Q& rhs){ return !(lhs == rhs); }

	template<typename IO>
	friend IO& operator <<(IO& ostream, const Mint& _x){
		return ostream << _x.val;
	}
	template<typename IO>
	friend IO& operator >>(IO& istream, Mint& _x){
		return istream >> _x.val;
	}
};
using mi = Mint<long long, 998'244'353>;

mi S = 0, S2 = 0;
int cnt[N], a[N];
int Main(){
	S = 0; S2 = 0;
	int n;
	cin >> n;
	mi ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[i] = 1;
		for(int j = i; j > 0; j--){
			if((a[j] / cnt[j]) >= ((a[j - 1] + cnt[j - 1] - 1) / cnt[j - 1]) ) break;
			S2 -= 1ll * (cnt[j - 1] - 1) * j;
			cnt[j - 1] = (a[j - 1] + ((a[j] / cnt[j]) - 1)) / (a[j] / cnt[j]);
			S2 += 1ll * (cnt[j - 1] - 1) * j;
		}
		ans += S2;
		// cerr << "! " << S2 << '\n';
	}

	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}
/*
1
3
5 4 3

*/