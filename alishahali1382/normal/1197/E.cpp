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
const int MAXN = 400010, LOG=20;

ll n, m, k, u, v, x, y, t, l, r, ans, mn, mndp=inf;
ll dp[2*MAXN];
ll cnt[2*MAXN];
pii A[MAXN];
vector<int> vec;
vector<int> V[2*MAXN];

int get_ind(int x){ return lower_bound(all(vec), x)-vec.begin();}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>r>>l;
		A[i]={l, r};
		vec.pb(l);
		vec.pb(r);
		mn=max(mn, l);
	}
	vec.pb(0);
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	
	for (int i=1; i<=n; i++) V[get_ind(A[i].second)].pb(get_ind(A[i].first));
	
	dp[0]=0;
	int sz=vec.size();
	for (int i=1; i<sz; i++){
		dp[i]=dp[i-1]+vec[i]-vec[i-1];
		for (int x:V[i]) dp[i]=min(dp[i], dp[x]);
		if (V[i].size() && vec[i]>mn) mndp=min(mndp, dp[i]);
	}
	cnt[0]=1;
	for (int i=1; i<sz; i++){
		for (int x:V[i]) if(dp[i]==dp[x]) cnt[i]+=cnt[x];
		cnt[i]%=mod;
		if (V[i].size() && vec[i]>mn && dp[i]==mndp) ans+=cnt[i];
		if (dp[i]==dp[i-1]+vec[i]-vec[i-1]) cnt[i]+=cnt[i-1];
		//debug2(vec[i], cnt[i])
	}
	cout<<ans%mod<<'\n';
	
	return 0;
}