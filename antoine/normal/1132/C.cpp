#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = 5009;
int a[MxN + 9];
int l[MxN + 9];
int r[MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < q; ++i) {
		cin >> l[i] >> r[i];
		++a[l[i]];
		--a[r[i] + 1];
	}

	partial_sum(begin(a), end(a), a);

	int ans = 0;

	for (int i = 0; i < q; ++i) {
		for (int x = l[i]; x <= r[i]; ++x)
			--a[x];

		int temp = 0;
		for (int i = 1; i <= n; ++i)
			temp += a[i] != 0;

		static int cs[MxN + 9];
		cs[0] = 0;
		for (int i = 1; i <= n; ++i)
			cs[i] = cs[i - 1] + (a[i] == 1);

		for (int j = i + 1; j < q; ++j)
			ans = max(ans, temp - (cs[r[j]] - cs[l[j] - 1]));

		for (int x = l[i]; x <= r[i]; ++x)
			++a[x];

	}
	cout << ans;
	return 0;
}