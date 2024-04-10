#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int p[(int)2e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 2; i <= n; ++i)
		cin >> p[i];

	vector<int> res;
	for(int i = n;i; i = p[i])
		res.push_back(i);

	reverse(res.begin(), res.end());
for(auto &&x : res) cout << x << ' ';
	return 0;
}