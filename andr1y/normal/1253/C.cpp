#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200005
#define INF 101111111111111
using namespace std;
ll a[N], s[N], os[N], res[N];
ll n, m;
int main(){
	FAST;
	cin >> n >> m;
	for(ll i =0;i<n;i++) cin >> a[i];
		sort(a, a+n);
	ll nowzs = 0, oldr = 0;
	for(ll i =0;i<n;i++){
		//s[nowzs] *= i/m+1;
		res[i] = oldr + os[nowzs]+a[i];
		s[nowzs] += os[nowzs];
		s[nowzs] += a[i];
		os[nowzs] += a[i];
		oldr = res[i];
		nowzs = (nowzs+1)%m;
	}
	for(ll i = 0;i<n;i++) cout << res[i] << " ";
		cout << endl;
}