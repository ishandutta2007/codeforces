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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=1010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN][MAXN];

void Solve(){
	ans=0;
	cin>>n;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin>>A[i][j];
	int x=1, y=1, xx=n, yy=n;
	
	while (x<xx){
		vector<int> shit;
		for (int i=x; i<xx; i++) shit.pb(A[i][y]);
		for (int i=y; i<yy; i++) shit.pb(A[xx][i]);
		for (int i=xx; i>x; i--) shit.pb(A[i][yy]);
		for (int i=yy; i>y; i--) shit.pb(A[x][i]);
//		debugv(shit)
		for (int i=0; i<SZ(shit); i+=4) ans^=shit[i]^shit[i+1];
		x+=2;
		y+=2;
		xx-=2;
		yy-=2;
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}