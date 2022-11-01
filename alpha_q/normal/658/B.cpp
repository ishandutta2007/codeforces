#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 2e5;

priority_queue <pii> PQ;
int n, k, q, t[N];

bool Check (int id) {
	pii a[10];
	bool flag = 0;
	int i;
	for (i = 1; i <= k; i++) {
		if (PQ.empty()) break;
		a[i] = PQ.top();
		PQ.pop();
		if (a[i].second == id) flag = 1;
	}
	for (int j = i - 1; j >= 1; j--) PQ.push(a[j]);
	return flag;
}

int main() {	
	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &n, &k, &q);
	for (int i = 1; i <= n; i++) scanf("%d", t + i);

	int com, id;
	while (q--) {
		scanf("%d %d", &com, &id);
		if (com == 1) PQ.push(make_pair(t[id], id));
		else printf("%s\n", Check(id) ? "YES" : "NO");
	}
    return 0;
}