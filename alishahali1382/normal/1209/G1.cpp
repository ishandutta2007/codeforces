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
int A[MAXN];
int last[MAXN];
int par[MAXN];
bool mark[MAXN];
vector<int> vec[MAXN];
vector<int> comp[MAXN];

int get(int x){
	if (par[x]==x) return x;
	return par[x]=get(par[x]);
}

void change(int x, int y){
	par[get(x)]=get(y);
	for (int i:vec[x]) A[i]=y, last[y]=max(last[y], i);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<MAXN; i++) par[i]=i;
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], vec[A[i]].pb(i), last[A[i]]=i;
	for (int i=1; i<=n; i++) if (!mark[A[i]]){
		mark[A[i]]=1;
		for (int j=i+1; j<=last[A[i]]; j++) if (A[i]!=A[j]) change(A[j], A[i]);
	}
	for (int i=1; i<=n; i++) cerr<<A[i]<<" \n"[i==n];
	for (int i=1; i<MAXN; i++) comp[get(i)].pb(vec[i].size());
	for (int i=1; i<MAXN; i++) if (comp[i].size()){
		sort(all(comp[i]));
		ans-=comp[i].back();
	}
	ans+=n;
	cout<<ans<<'\n';
	
	
	return 0;
}