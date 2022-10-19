#include<bits/stdc++.h>
 
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("trapv")
 
#define st first
#define nd second
#define pb push_back
#define eb emplace_back
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)
 
using namespace std;
 
///~~~~~~~~~~~~~~~~~~~~~~~~~~
 
template <typename H, typename T> 
ostream& operator<<(ostream& os, pair<H, T> m){
	return os <<"("<< m.st<<", "<<m.nd<<")";
}
template <typename H> 
ostream& operator<<(ostream& os, vector<H> V){
	os<<"{";
	for(int i=0; i<V.size(); i++){
		if(i)os<<" ";
		os<<V[i];
	}
	os<<"}";
	return os;
}
 
void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);
 
///~~~~~~~~~~~~~~~~~~~~~~~~~
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;
 
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
const int N=2e5+5, INF=1e9+5, mod=1e9+7;//998244353;

struct modint{
	int n=0;
	modint(){}
	modint(ll x){
		n=x%mod;
		if(n<0)n+=mod;
	}
	operator int(){
		return n;
	}
	modint operator+(modint a){a.n = n+a.n; if(a.n>=mod)a.n-=mod;return a;}
	modint operator+=(modint a){return (*this)=(*this)+a;}
	modint operator-(modint a){a.n = n-a.n; if(a.n<0)a.n+=mod;return a;}
	modint operator-=(modint a){return (*this)=(*this)-a;}
	modint operator*(modint a){a.n = (n*1ll*a.n)%mod; return a;}
	modint operator*=(modint a){return (*this)=(*this)*a;}
	modint operator^(const ll &m)const{
		modint a(1);
		if(m==0)return a;
		if(m==1)return (*this);
		a=(*this)^(m/2);
		a*=a;
		return a*((*this)^(m&1));
	}
	modint odw(){
		return (*this)^((ll)mod-2);
	}
	modint operator/(modint a){return (*this)*a.odw();}
	modint operator/=(modint a){return (*this)=(*this)/a;}
	bool operator==(modint a){return a.n==n;}
	friend ostream& operator<<(ostream& os, modint m) {
		return os << m.n; 
	}
};
modint fact[N], fact2[N];
typedef vector<modint> vm;
void factinit(){
    fact[0]=1;
    for(int i=1; i<N; i++){
        fact[i]=(fact[i-1]*modint(i))%mod;
    }
    fact2[N-1]=fact[N-1].odw();
    for(int i=N-2; i>=0; i--){
    	fact2[i]=(fact2[i+1]*modint(i+1))%mod;
    }
}
modint npok(int _n, int _k){
    return fact[_n]*fact2[_k]*fact2[_n-_k];
}

int main(){
	//factinit();
	//BOOST;
	int tt;
	cin>>tt;
	while(tt--){
		int n, k;
		cin>>n>>k;
		str s;
		cin>>s;
		vi ile(26);
		for(int i=0; i<n; i++){
			ile[s[i]-'a']++;
		}
		//deb(s);
		int t=k;
		vector<char> V;
		for(int i=0; i<26; i++){
			if(i>=n/k)ile[i]=0;
			//cout<<ile[i]<<"\n";
			if(ile[i]<t){
				for(int j=ile[i]; j<t; j++){
					V.pb('a'+i);
				}
				t=ile[i];
			}
		}
		rev(V);
		for(char i:V)cout<<i;
		cout<<"\n";
	}
}