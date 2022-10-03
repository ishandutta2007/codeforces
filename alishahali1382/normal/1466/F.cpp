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
const int MAXN=500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN], good[MAXN];
int A[MAXN], B[MAXN];
vector<int> out;

int get(int x){ return (par[x]==x?x:par[x]=get(par[x]));}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	iota(par+1, par+m+1, 1);
	for (int i=1; i<=n; i++){
		cin>>k>>A[i];
		if (k==2){
			cin>>B[i];
//			par[get(A[i])]=get(B[i]);
		}
	}/*
	for (int i=1; i<=n; i++) if (!B[i]){
		int x=get(A[i]);
		if (!good[x]){
			good[x]=1;
			ans++;
			out.pb(i);
		}
	}*/
	iota(par+1, par+m+1, 1);
	for (int i=1; i<=n; i++){
		x=get(A[i]);
		if (!B[i]){
			if (good[x]) continue ;
			good[x]=1;
			out.pb(i);
			ans++;
			continue ;
		}
		y=get(B[i]);
		if (x==y) continue ;
		if (good[x]) swap(x, y);
		if (good[x]) continue ;
		par[x]=y;
		ans++;
		out.pb(i);
	}
	ll res=1;
	for (int i=0; i<ans; i++) res=res*2%mod;
	cout<<res<<" "<<ans<<"\n";
	sort(all(out));
	for (int i:out) cout<<i<<" ";cout<<"\n";
	
	return 0;
}