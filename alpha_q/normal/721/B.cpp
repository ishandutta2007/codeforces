#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, k;
string p[N], s;

bool cmp (string a, string b) {
	if (a.size() == b.size()) return a[0] < b[0];
	return a.size() < b.size();
}

int main (int argc, char const *argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    cin >> s;
	
	sort(p + 1, p + n + 1, cmp);
	int l = (int) s.size();

	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		if ((int) p[i].size() < l) ++tot;
		else if ((int) p[i].size() == l) {
			int cnt = 0;
			while (i <= n and (int) p[i].size() == l) ++cnt, ++i;
			cout << 1 + tot + 5 * (tot/k) << ' ';
			tot += (cnt - 1);
			cout << 1 + tot + 5 * (tot/k) << '\n';
			return 0; 
		}
	}
    return 0;
}