#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int MAXN = 1010, LOG=10;

int n, m, k, u, v, x, y, xx, yy, t, a, b, ans;
short SP[MAXN][MAXN][LOG][LOG];

int get(int x, int y, int xx, int yy){
	//cerr<<"get "<<x<<' '<<y<<' '<<xx<<' '<<yy<<'\n';
	int i=log2(xx-x), j=log2(yy-y);
	return max(max(SP[x][y][i][j], SP[xx-(1<<i)][y][i][j]), max(SP[x][yy-(1<<j)][i][j], SP[xx-(1<<i)][yy-(1<<j)][i][j]));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>>SP[i][j][0][0];
	for (int x=n; x; x--) for (int y=m; y; y--){
		SP[x][y][0][0]*=min(min(SP[x+1][y][0][0], SP[x][y+1][0][0]), SP[x+1][y+1][0][0])+1;
		for (int i=1; i<LOG && x+(1<<i)<MAXN; i++) SP[x][y][i][0]=max(SP[x][y][i-1][0], SP[x+(1<<(i-1))][y][i-1][0]);
		for (int i=0; i<LOG && x+(1<<i)<MAXN; i++) for (int j=1; j<LOG && y+(1<<j)<MAXN; j++) SP[x][y][i][j]=max(SP[x][y][i][j-1], SP[x][y+(1<<(j-1))][i][j-1]);
	}
	
	cin>>t;
	while (t--){
		cin>>x>>y>>xx>>yy;
		xx++;yy++;
		int dwn=0, up=min(xx-x, yy-y)+1;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			if (get(x, y, xx-mid+1, yy-mid+1)>=mid) dwn=mid;
			else up=mid;
		}
		cout<<dwn<<'\n';
	}
	
	
	return 0;
}