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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN];
bool bad[MAXN];
pair<int, pii> E[MAXN];

int get(int x){
	if (par[x]==x) return x;
	return par[x]=get(par[x]);
}

int join(int x, int y){
	x=get(x);
	y=get(y);
	if (x==y){
		if (bad[x]) return 0;
		bad[x]=1;
		return 1;
	}
	if (bad[x] && bad[y]) return 0;
	par[x]=y;
	bad[y]|=bad[x];
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++) cin>>E[i].second.first>>E[i].second.second>>E[i].first;
	sort(E, E+m);
	reverse(E, E+m);
	iota(par, par+MAXN, 0);
	for (int i=0; i<m; i++) ans+=join(E[i].second.first, E[i].second.second)*E[i].first;
	cout<<ans<<'\n';
	
	return 0;
}