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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int dp[MAXN];
int Rank[LOG][MAXN], P[MAXN], pw;
int lcp[LOG][MAXN], Lg[MAXN];
int shit[MAXN];
int pos[MAXN], root[MAXN];
int seg[MAXN*LOG], L[MAXN*LOG], R[MAXN*LOG], N;
vector<int> vec[MAXN*2];
string S;

bool cmp(int x, int y){
	if (Rank[pw-1][x]!=Rank[pw-1][y]) return Rank[pw-1][x]<Rank[pw-1][y];
	if (max(x, y)+(1<<(pw-1))>n) return x>y;
	return Rank[pw-1][x+(1<<(pw-1))]<Rank[pw-1][y+(1<<(pw-1))];
}

void radix(){
	for (int i=1; i<=n; i++) vec[shit[P[i]]+MAXN].pb(P[i]);
	int cnt=1;
	for (int i=0; i<MAXN*2; i++){
		for (int id:vec[i]) P[cnt++]=id;
		vec[i].clear();
	}
}

void BuildSuffixArray(){
	for (int i=1; i<=n; i++) Rank[0][i]=shit[i]=S[i], P[i]=i;
	for (pw=1; pw<LOG; pw++){
		/*
		for (int i=1; i<=n; i++) shit[i]=(i+(1<<(pw-1))>n?-i:Rank[pw-1][i+(1<<(pw-1))]);
		radix();
		for (int i=1; i<=n; i++) shit[i]=Rank[pw-1][i];
		radix();
		*/
		sort(P+1, P+n+1, cmp);
		for (int i=2; i<=n; i++) Rank[pw][P[i]]=Rank[pw][P[i-1]]+cmp(P[i-1], P[i]);
	}
}

int GetLcp(int x, int y){
	int res=0;
	for (int i=LOG-1; ~i && max(x, y)<=n; i--) if (Rank[i][x]==Rank[i][y]){
		res|=(1<<i);
		x+=(1<<i);
		y+=(1<<i);
	}
	return res;
}

int Lcp(int i, int j){
	int l=pos[i], r=pos[j];
	if (l>r) swap(l, r);
	int lg=Lg[r-l];
	return min(lcp[lg][l], lcp[lg][r-(1<<lg)]);
}

int Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return id;
	int res=++N;
	if (tr-tl==1){
		seg[res]=val;
		return res;
	}
	int mid=(tl+tr)>>1;
	L[res]=Set(L[id], tl, mid, pos, val);
	R[res]=Set(R[id], mid, tr, pos, val);
	seg[res]=max(seg[L[res]], seg[R[res]]);
	return res;
}

int Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return max(Get(L[id], tl, mid, l, r), Get(R[id], mid, tr, l, r));
}

bool check(int i, int len, int id){
	int l, r;
	int dwn=0, up=pos[i];
	while (up-dwn>1){
		int mid=(dwn+up)>>1;
		if (Lcp(P[mid], i)>=len) up=mid;
		else dwn=mid;
	}
	l=up;
	dwn=pos[i], up=n+1;
	while (up-dwn>1){
		int mid=(dwn+up)>>1;
		if (Lcp(i, P[mid])>=len) dwn=mid;
		else up=mid;
	}
	r=up;
	return Get(id, 1, n+1, l, r)>=len;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) Lg[i]=Lg[i>>1]+1;
	cin>>n>>S;
	S="."+S;
	BuildSuffixArray();
	for (int i=1; i<n; i++) lcp[0][i]=GetLcp(P[i], P[i+1]);
	for (int j=1; j<LOG; j++) for (int i=1; i+(1<<j)<=n; i++) lcp[j][i]=min(lcp[j-1][i], lcp[j-1][i+(1<<(j-1))]);
	for (int i=1; i<=n; i++) pos[P[i]]=i;
	
	for (int i=n; i; i--){
		dp[i]=dp[i+1]+1;
		while (!check(i, dp[i]-1, root[i+dp[i]]) && !check(i+1, dp[i]-1, root[i+dp[i]])) dp[i]--;
		root[i]=Set(root[i+1], 1, n+1, pos[i], dp[i]);
	}
	cout<<*max_element(dp+1, dp+n+1)<<'\n';
	
	return 0;
}