# include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
const ll MOD = 1e9+7;
typedef string str;
template<ll Mod>
struct ModInt {
    ll val;

    ModInt() : val(0) {}
    template <class U> ModInt(const U& x){
        val = (-Mod < x && x < Mod) ? x : x % Mod;
        val = (val < 0) ? val + Mod : val;
    }

    friend ostream &operator<<(ostream &os, ModInt x) { return os << x.val;}
    friend istream &operator>>(istream &is, ModInt &x) { return is >> x.val;}

    friend ModInt operator+(ModInt x, ModInt y) { return ModInt(x.val + y.val);}
    friend ModInt operator-(ModInt x, ModInt y) { return ModInt(x.val - y.val);}
    friend ModInt operator*(ModInt x, ModInt y) { if (Mod > ll(2e9)) return x.LogMul(x, y); return ModInt(x.val * y.val);}
    friend ModInt operator/(ModInt x, ModInt y) { return x * x.inv(y); }
    friend ModInt operator^(ModInt x, ll y) {
        ModInt ans = 1;
        for(; y ; y /= 2 , x *= x)  if(y & 1)   ans *= x;
        return ans;
    }

    template<class T> ModInt operator+=(T x) { return (*this) = (*this) + x;}
    template<class T> ModInt operator-=(T x) { return (*this) = (*this) - x;}
    template<class T> ModInt operator*=(T x) { return (*this) = (*this) * x;}
    template<class T> ModInt operator/=(T x) { return (*this) = (*this) / x;}
    template<class T> ModInt operator^=(T x) { return (*this) = (*this) ^ x;}

    ModInt inv(ModInt x) { return ModInt(x.val) ^ (Mod - 2); }

    ModInt LogMul(ModInt x, ModInt y) {
        if (y.val == 1) return x;
        return LogMul(ModInt(2 * x.val), ModInt(y.val / 2)) + (y.val % 2 == 1 ? x.val : 0);
    }
};

using mll = ModInt<MOD>;
 
 
# define endl		 '\n'
# define sep		 ' '
# define F 			 first
# define S 			 second
# define pb			 push_back
# define fast_io 	 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b);}

 
const int xn = 1e5+10;
const int xm = 5e4+10;
 
mll ent[2][xn], ans;
ll n, k, ps[xn];
string b; 
 
 
int main(){
	fast_io;
	
	cin >> n >> k >> b;
	
	
	if (k == 0){
		for (int i=0; i<n; i++) ans *= mll(10), ans += mll(b[i]-'0');
		cout << ans << endl;
		return 0;
	}
	
	
	ent[1][k-1] = 1;
	for (ll i=k; i<=n; i++) ent[1][i] = (ent[1][i-1] * mll(i) / (mll(i) - mll(k) + mll(1)));
	
	ent[0][k] = 1;
	for (ll i=k+1; i<=n; i++) ent[0][i] = (ent[0][i-1] * mll(i) / (mll(i) - mll(k)));
	
	for (int i=1; i<=n; i++) ps[i] = ps[i-1] + ll(b[i-1]-'0');
	
	//cout << ent[1][0] << endl;
	
	for (ll x = 0; x < n-k; x++){
		mll s = 1;
		s *= ent[1][n-x-2];
		s *= mll(10) ^ x;
		s *= mll(ps[n-x-1]);
		
		ans += s;
		
		s = mll(b[n-x-1]-'0') * ent[0][n-x-1];
		s *= mll(10)^x;
		ans += s;
		
		
	}
	
	cout << ans << endl;
	
	return 0;
}
 
/*
5 2
39923
2667
*/