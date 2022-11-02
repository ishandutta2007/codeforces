#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int maxn = (int) 1e6 + 100;
ll x, y;
char s[maxn], t[maxn];
map<int, int> M[maxn];
void solve(){
	scanf("%lld%lld%s%s", &x, &y, s, t);
	ll n = strlen(s);
	ll m = strlen(t);
	ll g = __gcd(n, m);
	ll len = n * m/g;
	ll ans = len;
	for(int i = 0; i < n; i++) {
		M[i % g][s[i]]++;
	}
	for(int i = 0; i < m; i++) {
		ans -= M[i % g][t[i]];
	}
	printf("%lld\n", (x*n)/len * ans);

}
int main(){
	solve();
	return 0;
}