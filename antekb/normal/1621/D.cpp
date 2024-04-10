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

const int N=3e5+5, mod=1e9+7, INF=1e9+5;

int main(){
	BOOST;
	int tt=1;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		ll ans=0;
		int c=INF;
		for(int i=0; i<2*n; i++){
			for(int j=0; j<2*n; j++){
				int x;
				cin>>x;
				if(i>=n && j>=n)ans+=x;
				if((i==n || i==2*n-1) && (j==n-1 || j==0))c=min(c, x);
				if((j==n || j==2*n-1) && (i==n-1 || i==0))c=min(c, x);
			}
		}
		cout<<ans+c<<"\n";
	}
}