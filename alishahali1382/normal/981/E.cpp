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
const int MAXN = 10010, LOG=20;

int n, m, k, u, v, x, y, t, l, r, cnt;
vector<int> seg[MAXN<<2];
bitset<MAXN> B[LOG], ans;

void Add(int id, int tl, int tr, int l, int r, int x){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		seg[id].pb(x);
		return ;
	}
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, x);
	Add(id<<1 | 1, mid, tr, l, r, x);
}

void dfs(int id, int tl, int tr){
	B[cnt]=B[cnt-1];
	for (int x:seg[id]) B[cnt]|=(B[cnt]<<x);
	if (tr-tl==1){
		ans|=B[cnt];
		return ;
	}
	cnt++;
	int mid=(tl+tr)>>1;
	dfs(id<<1, tl, mid);
	dfs(id<<1 | 1, mid, tr);
	cnt--;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>l>>r>>x;
		Add(1, 1, n+1, l, r+1, x);
	}
	B[cnt++].set(0);
	dfs(1, 1, n+1);
	for (int i=1; i<=n; i++) k+=ans[i];
	cout<<k<<'\n';
	for (int i=1; i<=n; i++) if (ans[i]) cout<<i<<' ';
	
	return 0;
}