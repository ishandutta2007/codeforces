#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, c, ans;
ll dp[MAXN];
bool mark[MAXN];

int Solve(){
	cin>>n>>k;
	if (n<61 && k>(1ll<<(n-1))) kill(-1)
	k--;
	int nn=n, i=1;
	while (nn>61){
		cout<<i<<" ";
		i++;
		nn--;
	}
	while (i<=n){
		int j=i;
		while (j<n){
			ll val=(1ll<<(nn-2));
			if (nn<=2) val=1;
			if (k<val) break ;
			j++;
			nn--;
			k-=val;
		}
		nn--;
		for (int t=j; t>=i; t--) cout<<t<<" ";
		i=j+1;
	}
	cout<<"\n";

}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}