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
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=400010, SZ=2*20*MAXN;

int n, m, q, u, v, x, y, t, a, b, lis, ans;
int A[MAXN], B[MAXN], dp[MAXN], pd[MAXN];
int pref[MAXN], suff[MAXN];
int ted[MAXN], good[MAXN];
int L[SZ], R[SZ], seg[SZ], ts;

int Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return id;
	int res=++ts;
	if (tr-tl==1){
		seg[res]=max(seg[id], val);
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

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>q;
	for (int i=1; i<=n; i++) cin>>A[i], B[i-1]=A[i];
	sort(B, B+n);
	m=unique(B, B+n)-B;
	for (int i=1; i<=n; i++){
		A[i]=lower_bound(B, B+m, A[i])-B;
		dp[i]=Set(dp[i-1], 0, m, A[i], pref[i]=Get(dp[i-1], 0, m, 0, A[i])+1);
	}
	for (int i=n; i; i--)
		pd[i]=Set(pd[i+1], 0, m, A[i], suff[i]=Get(pd[i+1], 0, m, A[i]+1, m)+1);
	
	lis=seg[dp[n]];
	for (int i=1; i<=n; i++) if (pref[i]+suff[i]-1==lis) ted[pref[i]]++;
	for (int i=1; i<=n; i++) if (pref[i]+suff[i]-1==lis && ted[pref[i]]==1) good[i]=1;
	while (q--){
		cin>>x>>y;
		a=lower_bound(B, B+m, y)-B-1;
		b=upper_bound(B, B+m, y)-B;
		ans=Get(dp[x-1], 0, m, 0, a+1) + Get(pd[x+1], 0, m, b, m)+1;
		ans=max(ans, lis-good[x]);
		cout<<ans<<"\n";
	}
	
	return 0;
}