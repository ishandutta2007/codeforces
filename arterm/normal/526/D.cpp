#include <bits/stdc++.h>

using namespace std;

const int M = 1000100;

int n, k;
string s;
int p[M], z[M], sum[M];

void read() {
	cin >> n >> k;
	cin >> s;
}

void cmp() {
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j])
			++j;
		p[i] = j;
	}
}

void zFunction(const string &s) {
    int n = s.length(), l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = max(0, min(r - i, z[i - l]));

        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];

        if (i + z[i] >= r) {
            r = i + z[i];
            l = i;
        }
    }
}

void kill() {
	for (int i = 1; i * k <= n; ++i) {
		int d = i * k - p[i * k - 1];
		if (i % d != 0)
			continue;
		
		int t = min(z[i * k], i);
		sum[i * k - 1]++;
		sum[i * k + t]--;
	}
	for (int i = 1; i <= n; ++i)
		sum[i] += sum[i - 1];
	string ans(n, '0');
	for (int i = 0; i < n; ++i)
		if (sum[i] > 0)
			ans[i] = '1';
	cout << ans << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	read();
	cmp();
	zFunction(s);
	kill();
	return 0;
}