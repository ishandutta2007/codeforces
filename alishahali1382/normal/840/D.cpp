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
const int mod = 1000000007;
const int MAXN = 300010, LOG=20;

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
vector<int> vec[MAXN];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int f(int a, int l, int r, int k){
	int t=(r-l)/k;
	int ind=lower_bound(all(vec[a]), l)-vec[a].begin();
	if (ind+t>=vec[a].size()) return 0;
	return vec[a][ind+t]<r;
}

int solve(){
	ans=inf;
	cin>>l>>r>>k;
	++r;
	for (int i=0; i<70; i++){
		int a=A[l + rng()%(r-l)];
		if (f(a, l, r, k)) ans=min(ans, a);
	}
	if (ans==inf) ans=-1;
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], vec[A[i]].pb(i);
	while (m--) solve();
	
	return 0;
}