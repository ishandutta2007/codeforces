#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
const int maxn = 1e6 + 1, INF = 1e9;
const ll llINF = 1e18;

vector<int> lo(maxn, -1);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i = 2; i <= maxn; i++) if(lo[i] == -1)
		for(int j = 2 * i; j <= maxn; j += i) lo[j] = i;
	int x; cin >> x;
	int p = lo[x];
	int l = x - p + 1, r = x;
	int ans = INF;
	for(int i = l; i <= r; i++) if(lo[i] != -1) ans = min(ans, i - lo[i] + 1);
	cout << ans;
}