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

const int N=3e5+5, mod=1e9+7, INF=1e9+5;
vi co[N];
int main(){
	BOOST;
	int n, k;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		int j=i;
		while(j){
			co[i].pb(j%k);
			j/=k;
		}
	}
	for(int i=0; i<n; i++){
		co[i].resize(co[n-1].size());
		rev(co[i]);
	}
	cout<<co[n-1].size()<<"\n";
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int t=0; ; t++){
				if(co[i][t]!=co[j][t]){
					cout<<t+1<<" ";
					break;
				}
			}
		}
	}
}