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

const int N=3e5+5, K=18, mod=1e9+7, INF=1e9+5;
void solve(){
	int n, q;
	cin>>n>>q;
	str s;
	cin>>s;
	int ile=0;
	for(int i=0; i<n-2; i++){
		if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c')ile++;
	}
	while(q--){
		int t;
		char c;
		cin>>t>>c;
		t--;
		for(int i=max(0, t-2); i<=t && i<n-2; i++){
			if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c')ile--;
		}
		s[t]=c;
		for(int i=max(0, t-2); i<=t && i<n-2; i++){
			if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c')ile++;
		}
		cout<<ile<<"\n";
	}
}
int main(){
	BOOST;
	int t=1;
	//cin>>t;
	while(t--)solve();
}