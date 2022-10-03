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

ll n, m, k, s, t, u, a, b, ans;
ll A[MAXN];
ll X[MAXN];
map<pii, int> mp;

void upd(int i, ll delta){
	ans-=max(0ll, A[i]-X[i]);
	X[i]+=delta;
	ans+=max(0ll, A[i]-X[i]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], ans+=A[i];
	cin>>m;
	while (m--){
		cin>>s>>t>>u;
		if (mp.count({s, t})){
			upd(mp[{s, t}], -1);
			mp.erase({s, t});
		}
		if (u){
			mp[{s, t}]=u;
			upd(u, +1);
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}