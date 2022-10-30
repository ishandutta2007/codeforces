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
#define N 100005
#define INF 101111111111111
using namespace std;
ll p[N];
main(){
    FAST;
    ll n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i =1;i<=m;i++) scanf("%lld", &p[i]);
    ll x = 1, skip = 0, ans = 0;
	while(x <= m){
		ll eob = ((p[x] - skip - 1)/k + 1)*k + skip;
		while(x <= m && p[x] <= eob){
			++x, skip++;
		}
		ans++;
	}
	cout << ans;
}