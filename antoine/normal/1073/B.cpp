#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool done[(int) 2e5 + 99];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	reverse(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (done[x])
			cout << "0 ";
		else {
			int res = 0;
			do {
				assert(!a.empty());
				res++;
				done[a.back()] = true;
				a.pop_back();
			} while (!done[x]);
			cout << res << ' ';
		}
	}
	return 0;
}