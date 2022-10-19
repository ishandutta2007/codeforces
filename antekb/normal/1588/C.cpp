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

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=3e5+5, K=18, mod=998244353;
const ll INF=1e18;
ll tab[N][K];
int main(){
	BOOST;
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		vi V(n);
		vl t(n);
		vector<pair<ll, pii> > V2(n);
		for(int i=0; i<n; i++){
			cin>>V[i];
			//V[i]=0;
			t[i]=V[i];
			if(i)t[i]-=t[i-1];
			V2[i]=mp(t[i], mp(i&1, i));
			tab[i][0]=t[i];
		}
		sor(V2);
		for(int j=1; j<K; j++){
			for(int i=0; i<n; i++){
				if(i+(1<<j)>=n){
					tab[i][j]=-INF;
				}
				else{
					tab[i][j]=min(tab[i][j-1], tab[i+(1<<j)][j-1]);
				}
			}
		}
		//cout<<tab[0][2]<<"\n";
		ll ans=0;
		for(int i=0; i<n; i++){
			ll T=0;
			if(i)T=t[i-1];
			int r=n;
			if(t[i+1]<T)r=i+1;
			int i1=i, i2=i+1;
			for(int j=K-1; j>=0; j--){
				if(i1+(1<<(j+1))<=n+1 && tab[i1][j]>=-T){
					i1+=(1<<(j+1));
				}
				if(i2+(1<<(j+1))<=n+1 && tab[i2][j]>=T){
					i2+=(1<<(j+1));
				}
			}
			r=min(r, i1);
			r=min(r, i2);
			//deb(i1, i2, r);
			//cout<<i<<" "<<r<<" "<<ans<<"\n";
			int k=lower_bound(all(V2), mp(-T, mp(i&1, r)))-lower_bound(all(V2), mp(-T, mp(i&1, i)));
			ans+=k;
			k=lower_bound(all(V2), mp(T, mp(1^(i&1), r)))-lower_bound(all(V2), mp(T, mp(1^(i&1), i)));
			ans+=k;
			//deb(ans);
		}
		cout<<ans<<"\n";
	}
}