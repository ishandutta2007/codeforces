#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i];

	vector<pair<int, int>> q(n);
	for (int i = 0; i < n; ++i) {
		q[i].first = {n - p[i] - p[(i == n - 1 ? 0 : i + 1)]};
		q[i].second = i;
	}
	sort(all(q));
	reverse(all(q));
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[q[i].second] = i;
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

}