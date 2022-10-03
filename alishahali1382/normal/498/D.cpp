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
const int MAXN = 100010, C=3*4*5;

struct node{
	int dp[C];
	node(int x=0){
		fill(dp, dp+C, 1);
		if (x) for (int i=0; i<C; i+=x) dp[i]++;
	}
} seg[MAXN<<2];

int n, m, k, u, v, x, y, t, l, r;
int A[MAXN];
char ch;

node combine(node x, node y){
	node out;
	for (int t=0; t<C; t++) out.dp[t]=x.dp[t]+y.dp[(t+x.dp[t])%C];
	return out;
}

node build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]=node(A[tl]);
	int mid=(tl+tr)>>1;
	return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid, tr));
}

void update(int id, int tl, int tr, int pos){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id]=node(A[tl]);
		return ;
	}
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, pos);
	update(id<<1 | 1, mid, tr, pos);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

node get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return combine(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(seg[0].dp, 0, sizeof(seg[0].dp));
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	build(1, 1, n+1);
	
	cin>>m;
	while (m--){
		cin>>ch>>l>>r;
		if (ch=='A') cout<<get(1, 1, n+1, l, r).dp[0]<<'\n';
		else{
			A[l]=r;
			update(1, 1, n+1, l);
			continue ;
		}
	}
	
	return 0;
}