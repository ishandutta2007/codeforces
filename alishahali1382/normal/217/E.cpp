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
const int MAXN = 3000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int L[MAXN], R[MAXN];
int seg[MAXN<<2];
int par[MAXN];
char ans[MAXN];
string s;

int build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]=1;
	int mid=(tl+tr)>>1;
	return seg[id]=build(id<<1, tl, mid) + build(id<<1 | 1, mid, tr);
}

void Rem(int id, int tl, int tr, int pos){
	if (tr-tl==1){
		seg[id]=0;
		return ;
	}
	int mid=(tl+tr)>>1;
	if (pos<mid) Rem(id<<1, tl, mid, pos);
	else Rem(id<<1 | 1, mid, tr, pos);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];  // seg[id]--;
}

int get(int id, int tl, int tr, int pos){
	if (tr-tl==1) return tl;
	int mid=(tl+tr)>>1;
	if (seg[id<<1]>=pos) return get(id<<1, tl, mid, pos);
	return get(id<<1 | 1, mid, tr, pos-seg[id<<1]);
}

int Get(int pos){
	//debug2(pos, get(1, 1, k+1, pos))
	return get(1, 1, k+1, pos);
}

void solve(int n){
	int len=seg[1];
	//debug(len)
	if (n==0){
		for (int i=1; i<=len; i++) ans[Get(i)]=s[i-1];
		return ;
	}
	R[n]=min(len, R[n]);
	int l=min(len+1, R[n]+1), r=min(len, R[n]*2-L[n]+1);
	//cerr<<"n="<<n<<" : ";debug2(l, r)
	int pos=L[n]+1;
	for (int i=l; i<=r; i++){
		if (pos>R[n]) pos=L[n];
		par[Get(i)]=Get(pos);
		pos+=2;
	}
	for (int i=r; i>=l; i--) Rem(1, 1, k+1, Get(i));
	solve(n-1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s>>k>>n;
	for (int i=1; i<=n; i++) cin>>L[i]>>R[i];
	build(1, 1, k+1);
	solve(n);
	for (int i=1; i<=k; i++) if (!ans[i]) ans[i]=ans[par[i]];
	for (int i=1; i<=k; i++) cout<<ans[i];
	
	return 0;
}