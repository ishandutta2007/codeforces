#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("trapv")
#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)
 
using namespace std;
 
///~~~~~~~~~~~~~~~~~~~~~~~~~~
 
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
 
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
const int N=1e6+5, INF=1e9+5;
const int mod=998244353;
//const int mod=1e9+7;

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
ll gcd(ll a, ll b){
    if(!a) return b;
    return gcd(b%a, a);
}
ll pot(ll a, ll b){
    if(b==0) return 1ll;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=(c*c)%mod;
    return (c*pot(a, b&1))%mod;
}
modint npok(int _n, int _k){
    return fact[_n]*fact2[_k]*fact2[_n-_k];
}
pair<ll, pll> extgcd(ll a, ll b){
    if(a==0)return mp(b, mp(0, 1));
    if(b==0)return mp(a, mp(1, 0));
    auto d=extgcd(b%a, a);
    return mp(d.st, mp(d.nd.nd-d.nd.st*(b/a), d.nd.st));
}
ll mododw(ll x, ll p){
    return (extgcd(x,p).nd.st+p)%p;
}

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
    //assert(fact2[1]==1);
}
int main(){
	factinit();
	BOOST;
	int tt=1;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		vi V(n);
		for(int &i:V)cin>>i;
		sor(V);
		vi V2;
		int k=0;
		for(int i=0; i<=n; i++){
			if(i==n || (i>0 && V[i]!=V[i-1])){
				V2.pb(k);
				k=0;
			}
			k++;
		}
		if(V2.size()==1){
			cout<<1<<"\n";
			continue;
		}
		vi ile(n+1, 0);
		modint ans=0;
		int d=0;
		for(int i:V2)d=__gcd(d, i);
		vm num(n+1), num2(n+1);
		for(int i=d; i>=1; i--){
			if(d%i==0){
				modint s;
				for(int j:V2){
					s+=(j/i)*1ll*(n-j);
				}
				s/=(n/i-1);
				num[i]=fact[n/i];
				for(int j:V2){
					num[i]=(num[i]*fact2[j/i])%mod;
				}
				num2[i]=(num[i]*s)%mod;
				for(int j=d; j>i; j-=i){
					if(d%j==0){
						num[i]-=num[j]%mod;
						num2[i]-=num2[j];
					}
				}
			}
		}
		for(int i=d; i>=1; i--){
			if(d%i==0){
				num[i]=(num[i]/modint(n/i))%mod;
				num2[i]=(num2[i]/modint(n/i))%mod;
			}
		}
		modint sum=0;
		for(int i=1; i<=n; i++){
			if(ile[i]!=1 && d%i==0){
				int c=1-ile[i];
				ans+=num2[i];
				sum+=num[i];
			}
		}
		
		cout<<ans/sum<<"\n";
	}
}