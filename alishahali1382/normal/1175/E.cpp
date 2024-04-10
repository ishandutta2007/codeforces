#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int table[MAXN][LOG];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (n--){
		cin>>x>>y;
		table[x][0]=max(table[x][0], y);
	}
	for (int i=1; i<MAXN; i++) table[i][0]=max(table[i][0], table[i-1][0]);
	for (int j=1; j<LOG; j++) for (int i=1; i<MAXN; i++) table[i][j]=table[table[i][j-1]][j-1];
	while (m--){
		cin>>x>>y;
		ans=1;
		x=table[x][0];
		for (int i=LOG-1; i>=0; i--) if (table[x][i]<y) x=table[x][i], ans+=(1<<i);
		if (x<y) x=table[x][0], ans++;
		if (x<y) ans=-1;
		cout<<ans<<'\n';
	}
	
	return 0;
}