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

int n, m, k, u, v, x, y, t, a, b;
int X[MAXN], Y[MAXN], dead[MAXN], ans[MAXN];

ll dis(int i, int j){
	ll x=X[i]-X[j], y=Y[i]-Y[j];
	return x*x+y*y;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>X[i]>>Y[i];
	ans[1]=1;
	dead[1]=1;
	v=1;
	for (int i=2; i<=n; i++){
		int u=v;
		for (int j=1; j<=n; j++) if (!dead[j] && dis(v, j)>dis(v, u)) u=j;
		dead[u]=1;
		ans[i]=u;
		v=u;
	}
	for (int i=1; i<=n; i++) cout<<ans[i]<<" \n"[i==n];
	
	return 0;
}