#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

int answer;
int cnt[maxn];

void del(int v, int u) {
	if (v > u)
		swap(v, u);
	cnt[v]--;
	if (cnt[v] == 0)
		answer++;
}

void add(int v, int u) {
	if (v > u)
		swap(v, u);
	cnt[v]++;
	if (cnt[v] == 1)
		answer--;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	answer = n;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		add(v, u);
	}
	int q;
	cin >> q;
	while (q --) {
		int type;
		cin >> type;
		if (type == 3)
			cout << answer << '\n';
		else {
			int v, u;
			cin >> v >> u;
			if (type == 1)
				add(v, u);
			else
				del(v, u);
		}
	}
}