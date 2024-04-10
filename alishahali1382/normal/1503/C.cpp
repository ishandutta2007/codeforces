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

ll n, m, k, u, v, x, y, t, a, b, ans;
pll AA[MAXN];
ll A[MAXN], C[MAXN], dp[MAXN], mn[MAXN];
int ID[MAXN];
vector<ll> comp;

struct Segment{
	ll seg[MAXN<<1];
	Segment(){
		memset(seg, 63, sizeof(seg));
	}
	void Set(int pos, ll val){
		pos+=MAXN;
		seg[pos]=min(seg[pos], val);
		for (; pos>1; pos>>=1) seg[pos>>1]=min(seg[pos], seg[pos^1]);
	}
	ll Get(int l, int r){
		ll res=INF;
		for (l+=MAXN, r+=MAXN; l<r; l>>=1, r>>=1){
			if (l&1) res=min(res, seg[l++]);
			if (r&1) res=min(res, seg[--r]);
		}
		return res;
	}
} seg1, seg2;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>AA[i].first>>AA[i].second;
	sort(AA+1, AA+n+1);
	for (int i=1; i<=n; i++){
		A[i]=AA[i].first;
		C[i]=AA[i].second;
		comp.pb(A[i]+C[i]);
	}
	sort(all(comp));
	for (int i=1; i<=n; i++){
		ID[i]=lower_bound(all(comp), A[i]+C[i])-comp.begin();
//		debug2(i, ID[i])
	}
	seg1.Set(ID[1], dp[1]);
	seg2.Set(ID[1], dp[1]-A[1]-C[1]);
	for (int i=2; i<=n; i++){
		int pos=lower_bound(all(comp), A[i])-comp.begin();
		dp[i]=min(seg1.Get(pos, n), seg2.Get(0, pos)+A[i]);
//		debug2(seg1.Get(pos, n), seg2.Get(0, pos)+A[i])
		/*
		dp[i]=INF;
		for (int j=1; j<i; j++){
			if (A[i]<=C[j]+A[j]) dp[i]=min(dp[i], dp[j]);
			else dp[i]=min(dp[i], dp[j]-C[j]-A[j] + A[i]);
		}*/
		seg1.Set(ID[i], dp[i]);
		seg2.Set(ID[i], dp[i]-A[i]-C[i]);
//		debug2(i, dp[i])
//		cerr<<"\n";
	}
	ans=dp[n];
	for (int i=1; i<=n; i++) ans+=C[i];
	cout<<ans<<"\n";
	
	return 0;
}
/*
6
0 1
2 3
3 0
4 2
7 1
8 4

*/