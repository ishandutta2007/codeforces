#include <bits/stdc++.h>
#define bit(n, k) (((n)>>(k))&1)
using namespace std;

const int maxn = 1e5 + 10;

int last[30], nex[maxn], beg[30];
int fen[maxn];

void add(int idx, int x) {
	idx++;
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] += x;
}

int get(int idx) {
	idx++;
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i <= n; i++)
		nex[i] = -1, fen[i] = 0;
	memset(last, -1, sizeof last);
	memset(beg, -1, sizeof beg);
	for (int i = 0; i < n; i++) {
		int c = s[i] - 'a';
		if (last[c] != -1)
			nex[last[c]] = i;
		else
			beg[c] = i;
		last[c] = i;
	}
	for (int i = 0; i < n; i++)
		add(i, 1);
	long long answer = -1;
	long long untilNow = 0;
	for (int i = 0; i < n; i++) {
		int c = t[i] - 'a';
		for (int j = 0; j < c; j++) {
			if (beg[j] != -1) {
				long long newAnswer = untilNow + get(beg[j] - 1);
				if (answer == -1 || answer > newAnswer)
					answer = newAnswer;
			}
		}
		if (beg[c] == -1)
			break;
		untilNow += get(beg[c] - 1);
		add(beg[c], -1);
		beg[c] = nex[beg[c]];
	}
	cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}