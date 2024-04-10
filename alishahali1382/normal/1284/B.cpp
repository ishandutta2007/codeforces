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
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN];
vector<pii> vec;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		ll mn=inf, mx=-inf;
		bool good=0;
		cin>>t;
		while (t--){
			cin>>x;
			if (x>mn) good=1;
			mn=min(mn, x);
			mx=max(mx, x);
		}
		if (good) ans++;
		else vec.pb({mn, mx});
	}
	ans=ans*(n-ans)*2+ans*ans;
	sort(all(vec));
	for (pii p:vec){
		int x=p.second;
		int pos=lower_bound(all(vec), pii(x, -inf))-vec.begin();
		ans+=pos;
	}
	cout<<ans<<'\n';
	
	return 0;
}