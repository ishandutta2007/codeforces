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
const int mod = 777777777;
const int MAXN = 77778, LOG=20;

struct node{
	int dp[4][4];
	node(int x=0){
		memset(dp, 0, sizeof(dp));
		if (x && x<=3) dp[x][x]=1;
		if (x==4) dp[1][1]=dp[2][2]=dp[3][3]=1;
	}
	node operator =(node x){
		for (int i=1; i<=3; i++) for (int j=1; j<=3; j++) dp[i][j]=x.dp[i][j];
		return x;
	}
} seg[MAXN<<2];

int n, m, k, u, v, x, y, t, a, b;
ll W[4][4];

node operator *(node x, node y){
	node out(0);
	for (int i=1; i<=3; i++) for (int j=1; j<=3; j++) for (int k=1; k<=3; k++) for (int kk=1; kk<=3; kk++) out.dp[i][j]=(out.dp[i][j]+W[k][kk]*x.dp[i][k]*y.dp[kk][j])%mod;
	return out;
}

node build(int id, int tl, int tr){
	if (tl==tr){
		seg[id].dp[1][1]=seg[id].dp[2][2]=seg[id].dp[3][3]=1;
		return seg[id];
	}
	int mid=(tl+tr)>>1;
	return seg[id]=build(id<<1, tl, mid)*build(id<<1 | 1, mid+1, tr);
}

void update(int id, int tl, int tr, int pos, int val){
	if (tr<pos || pos<tl) return ;
	if (tl==tr){
		if (val) seg[id]=node(val);
		else seg[id]=node(4);
		return ;
	}
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, pos, val);
	update(id<<1 | 1, mid+1, tr, pos, val);
	seg[id]=seg[id<<1]*seg[id<<1 | 1];
	return ;
}

node get(int id, int tl, int tr, int l, int r){
	if (tr<l || r<tl) return node(4);
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) * get(id<<1 | 1, mid+1, tr, l, r);
}

void print(node x){
	for (int i=1; i<=3; i++) for (int j=1; j<=3; j++) cerr<<x.dp[i][j]<<" \n"[j==3];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=3; i++) for (int j=1; j<=3; j++) cin>>W[i][j];
	build(1, 1, n);
	while (m--){
		cin>>v>>t;
		update(1, 1, n, v, t);
		node tmp=get(1, 1, n, 1, n);
		ll ans=0;
		for (int i=1; i<=3; i++) for (int j=1; j<=3; j++) ans+=tmp.dp[i][j];
		cout<<ans%mod<<'\n';
	}
	
	
	return 0;
}