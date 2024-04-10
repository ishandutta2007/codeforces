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

const int N=2e5+5, mod=1e9+7, INF=1e9+5;

int main(){
	BOOST;
	int n, m;
	cin>>n>>m;
	vector<vector<int>> V(n, vi(m));
	for(int i=0; i<n; i++){
		str s;
		cin>>s;
		for(int j=0; j<m; j++){
			V[i][j]=(s[j]=='.');
		}
	}
	set<int> S;
	for(int i=0; i<n-1; i++){
		for(int j=1; j<m; j++){
			if(V[i][j]==0 && V[i+1][j-1]==0){
				S.insert(j);
			}
		}
	}
	//for(int i:S)cout<<i<<" ";
	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		int a, b;
		cin>>a>>b;
		if(S.lower_bound(a)!=S.lower_bound(b))cout<<"NO\n";
		else cout<<"YES\n";
	}
}