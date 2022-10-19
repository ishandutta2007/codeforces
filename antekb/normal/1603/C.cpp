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

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=5e5+5, mod=998244353, INF=1e9+5;
int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi V(n), ile(n, 1);
		ll ans=0, akt=0, sum=0;
		for(int i=0; i<n; i++){
			cin>>V[i];
			for(int j=i-1; j>=0; j--){
				if((V[j]+ile[j]-1)/ile[j]<=V[j+1]/ile[j+1])break;
				int t=((V[j]+V[j+1]/ile[j+1]-1)/(V[j+1]/ile[j+1]));
				//assert(ile[j]<t);
				akt+=(j+1)*1ll*(t-ile[j]);
				akt%=mod;
				//sum+=t-ile[j];
				ile[j]=t;
			}
			ans+=akt;
		}
		cout<<ans%mod<<"\n";
	}
}