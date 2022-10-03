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

ll n, m, k, u, v, x, y, t, a, b;
ld ps[MAXN];
ld mn[10];
ld ans;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=n; i++) cin>>ps[i], ps[i]+=ps[i-1]-(((ld)k)/m);
	for (int j=1; j<m; j++) mn[j]=1e15;
	for (int i=1; i<=n; i++){
		for (int j=0; j<m; j++){
			ans=max(ans, ps[i]-mn[(i+m-j)%m]-(j>0)*(m-j)*(1.*k/m));
		}
		mn[i%m]=min(mn[i%m], ps[i]);
	}
	debug(ans)
	ll tmp=ans;
	if (ans-tmp>=.5) tmp++;
	cout<<tmp<<'\n';
	
	return 0;
}