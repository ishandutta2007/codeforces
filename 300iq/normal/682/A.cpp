#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define INF (int) 1e9 + 7;
#define left left_fenwick
#define right right_fenwick
#define fc first
#define sc second
#define pb push_back
#define endl '\n'

int main() {
	ios_base::sync_with_stdio(0);
	//ifstream cin("input.txt");
	//ofstream cout("out.txt");
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for (int x = 1; x <= n; x++) {
		ans += (m + x) / 5 - (x / 5);
	}
	cout << ans << endl;
}