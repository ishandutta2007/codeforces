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

const int N=3e5+5, K=18, mod=998244353, INF=1e9+5;
void solve(){
	int n;
	cin>>n;
	vi A(n), B(n);
	for(int i=0; i<n; i++){
		cin>>A[i]>>B[i];
	}
	int l=1, r=n;
	while(l<r){
		int m=(l+r+1)>>1;
		int ile=0;
		for(int i=0; i<n; i++){
			if(ile<=B[i] && ile+1+A[i]>=m)ile++;
		}
		if(ile>=m)l=m;
		else r=m-1;
	}
	cout<<l<<"\n";
}
int main(){
	BOOST;
	int t=1;
	cin>>t;
	while(t--)solve();
}