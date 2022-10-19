#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ld INF=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ld a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	ld ans=INF;
	while(n--) {
		ld x, y, v;
		cin >> x >> y >> v;
		ans=min(ans, sqrt((x-a)*(x-a)+(y-b)*(y-b))/v);
	}
	cout << fixed << setprecision(6) << ans << '\n';
}