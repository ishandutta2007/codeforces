#include<bits/stdc++.h>

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

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi V(n+1), czy(n+1), V2(n+1);
		int ans=0;
		for(int i=1; i<=n; i++){
			int a;
			cin>>V2[i];
			a=V2[i];
			if(!czy[a]){
				V[i]=a;
				czy[a]=1;
				ans++;
			}
		}
		int wsk=1;
		vi zle;
		for(int i=n; i>0; i--){
			if(!V[i]){
				while(czy[wsk])wsk++;
				V[i]=wsk;
				wsk++;
				if(V[i]==i)zle.pb(i);
			}
		}
		if(zle.size()==1){
			int v=zle[0];
			for(int i=1; i<=n+1; i++){
				if(V[i]==V2[v]){
					V[i]=v;
					V[v]=V2[v];
				}
			}
		}
		else if(zle.size()>=2){
			assert(false);
		}
		cout<<ans<<"\n";
		for(int i=1; i<=n; i++){
			cout<<V[i]<<" ";
		}
		cout<<"\n";
	}
}