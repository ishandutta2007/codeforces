#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 2e5 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	bool ar[n][n];
	ms(ar);

	int c[n];
	ms(c);

	vector<ii> vec;

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		ar[a][b] = ar[b][a] = true;
		c[a]++, c[b]++;
		vec.push_back(make_pair(a, b));
	}

	int ans = INT_MAX;

	for(int j = 0; j < (int) vec.size(); j++){
		int a = vec[j].first, b = vec[j].second;
		for(int i = 0; i < n; i++)
			if(ar[a][i] && ar[b][i])
				ans = min(ans, c[i] + c[a] + c[b] - 6);
	}

	cout << (ans == INT_MAX ? -1 : ans);

}