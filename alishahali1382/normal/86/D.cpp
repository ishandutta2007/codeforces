#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
const int MAXN = 200010, SQ=500;
 
struct QUERY{
	int id, l, r, ll;
} query[MAXN];
 
bool moz(QUERY i, QUERY j){
	if (i.ll==j.ll) return (i.r<j.r)^(i.ll&1);
	return i.l<j.l;
}
 
int n, m, k, u, v, x, y, t, a, b;
ll val;
ll A[MAXN];
ll ans[MAXN];
int mp[1000010];
 
void upd(ll x, ll delta){
	val-=x*mp[x]*mp[x];
	mp[x]+=delta;
	val+=x*mp[x]*mp[x];
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=m; i++) cin>>a>>b, query[i]={i, a, b, a/SQ};
	sort(query+1, query+m+1, moz);
	int l=0, r=0;
	for (int i=1; i<=m; i++){
		while (l<query[i].l) upd(A[l++], -1);
		while (l>query[i].l) upd(A[--l], +1);
		while (r<query[i].r) upd(A[++r], +1);
		while (r>query[i].r) upd(A[r--], -1);
		ans[query[i].id]=val;
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}