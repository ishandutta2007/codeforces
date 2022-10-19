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

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll ans=0;
		vi V(n), ile(n);
		for(int i=0; i<n; i++){
			int x;
			cin>>V[i];
			if(i<n-1 && ile[i]>=V[i])ile[i+1]+=ile[i]-V[i]+1;
			else if(ile[i]>=V[i])ans+=ile[i]-V[i]+1;
			for(int j=i+2; (j<n) && (j-i<=V[i]); j++){
				ile[j]++;
			}
			//cout<<ile[i]<<" "<<" ";
			if(i==n-1)V[i]--;
			ans+=max(V[i]+i-n+1, 0);
		}
		cout<<ans<<"\n";
	}
}