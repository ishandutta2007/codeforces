#include<bits/stdc++.h>
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

const int N=4e5+5, INF=1e9+5, mod=998244353;
int fact[N];
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
int npok(int _n, int _k){
    return (((fact[_n]*1ll*pot(fact[_k], mod-2))%mod)*1ll*pot(fact[_n-_k], mod-2))%mod;
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
void factinit(){
    fact[0]=1;
    for(int i=1; i<N; i++){
        fact[i]=(fact[i-1]*1ll*i)%mod;
    }
}
int tab[2*N];
int sum(int l, int r){
	int ans=0;
	for(l+=N, r+=N; l<r; l>>=1, r>>=1){
		if(l&1)ans+=tab[l++];
		if(r&1)ans+=tab[--r];
	}
	return ans;
}
void add(int i, int c){
	int ans=0;
	for(i+=N; i>0; i>>=1){
		tab[i]+=c;
	}
	//return ans;
}
int main(){
	BOOST;
	factinit();
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vii V;
		for(int i=0; i<m; i++){
			int x, y;
			cin>>y>>x;
			V.push_back({x, y});
		}
		vii V2;
		vi V3;
		for(int i=m-1; i>=0; i--){
			int l=0, r=n-1;
			while(l<r){
				//cerr<<"a";
				int M=(l+r+1)>>1;
				if(M>=V[i].st+sum(0, M)){
					r=M-1;
				}
				else{
					l=M;
				}
			}
			//cout<<l<<"\n";
			//int t=sum(0, V[i].st+1);
			V2.push_back({l, V[i].nd});
			add(l, 1);
			V3.pb(l);
		}
		for(int i=0; i<m; i++){
			add(V3[i], -1);
		}
		sor(V2);
		//for(auto i:V2)cout<<i.st<<" "<<i.nd<<"\n";
		int cnt=0;
		for(int i=1; i<V2.size(); i++){
			if(V2[i].st==V2[i-1].st+1){
				if(V2[i].nd>V2[i-1].nd)cnt++;
			}
		}
		cnt=m-cnt;
		//cout<<cnt<<"\n";
		cnt=n-cnt;
		cout<<npok(n+cnt-1, n)<<"\n";
	}
}