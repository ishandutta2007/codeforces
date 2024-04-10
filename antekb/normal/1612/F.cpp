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

const int N=2e5+5, mod=1e9+7, INF=1e9+5;

int main(){
	int n, m;
	cin>>n>>m;
	bool sw=0;
	if(n>m)sw=1, swap(n, m);
	vector<vi> dp;
	int q;
	cin>>q;
	vii Q(q);
	for(pii &i:Q)cin>>i.st>>i.nd, i.st--, i.nd--;
	for(pii &i:Q)if(sw)swap(i.st, i.nd);
	sor(Q);
	int wsk=0;
	dp.pb(vi(n, -INF));
	dp.pb(vi(n, -INF));
	dp[0][0]=0;
	for(int j=0; ;j++){
		for(int i=0; i<n; i++)dp[(j&1)^1][i]=-INF;
		//cout<<"a\n";
		/*for(int i=n-2; i>=0; i--){
			dp[j][i]=max(dp[j][i], dp[j][i+1]);
		}*/
		for(int i=0; i<n; i++){
			if(dp[j&1][i]<0)continue;
			//cout<<dp[j][i]<<" ";
			if(i==n-1 && dp[j&1][i]>=m-1){
 				cout<<j<<"\n";
				return 0;
			}
			int czy=0;
			while(wsk<q && Q[wsk].st<=i){
				if(Q[wsk].st==i && Q[wsk].nd>dp[j&1][i])break;
				if(Q[wsk].st==i && Q[wsk].nd==dp[j&1][i])czy=1;
				wsk++;
			}
			dp[(j+1)&1][i]=max(dp[(j+1)&1][i], min(dp[j&1][i]+i+1+czy, m-1));
			dp[(j+1)&1][min(i+dp[j&1][i]+1+czy, n-1)]=max(dp[(j+1)&1][min(i+dp[j&1][i]+1+czy, n-1)], dp[j&1][i]);
		}
		//cout<<"\n";
	}
}