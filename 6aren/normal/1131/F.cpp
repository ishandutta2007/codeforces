#include <bits/stdc++.h>

using namespace std;

const int N = 150000 + 5;

int cha[N], leaf[N], n;

bool check[N];

vector<int> nebo[N];

int tim(int a) {
	if (cha[a]==a) return a;
    else {
        cha[a]=tim(cha[a]);
        return cha[a];
    }
}

void hop(int u, int v) {
	u = tim(u);
	v = tim(v);
	cha[v] = u;
	nebo[leaf[u]].push_back(v);
	nebo[v].push_back(leaf[u]);
	leaf[u] = leaf[v];
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		check[i] = true;
		cha[i] = i;
		leaf[i] = i;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		hop(u, v);
	}
	int s = tim(1);
	cout << s << " ";
	int cnt = 1;
	check[s] = false;

	while (cnt < n) {
		for (int i = 0 ; i < nebo[s].size(); i++) {
			if (check[nebo[s][i]]) {
				cout << nebo[s][i] << " ";
				check[nebo[s][i]] = false;
				cnt++;
				s = nebo[s][i];
			}
		}
	}
	return 0;
}