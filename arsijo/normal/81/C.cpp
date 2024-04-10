#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define y1 ngsdf
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;
const int MAX = 1e9;

int main() {

	int n;
	cin >> n;

	int a, b;
	cin >> a >> b;

	int ar[n];
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	int ans[n];

	if (a == b) {
		for (int i = 0; i < n; i++)
			ans[i] = (i < a ? 1 : 2);
	} else {
		vector<pair<int, int> > v;
		for (int i = 0; i < n; i++)
			v.push_back(make_pair(ar[i], (a > b ? i : -i)));
		sort(v.begin(), v.end());
		if (a > b) {
			for (int i = 0; i < n; i++)
				ans[i] = 2;
			for (int i = 0; i < a; i++)
				ans[v[i].second] = 1;
		} else {
			for (int i = 0; i < n; i++)
				ans[i] = 1;
			for (int i = 0; i < b; i++)
				ans[-v[i].second] = 2;
		}
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";

}