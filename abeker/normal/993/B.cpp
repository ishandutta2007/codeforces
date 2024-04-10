#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 105;

int N, M;
pii a[MAXN], b[MAXN];

int check(pii p, pii q) {
	if (p == q)
		return -1;
	if (p.first == q.first || p.first == q.second)
		return p.first;
	if (p.second == q.first || p.second == q.second)
		return p.second;
	return -1;
}

void norm(pii &p) {
	if (p.first > p.second)
		swap(p.first, p.second);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		norm(a[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &b[i].first, &b[i].second);
		norm(b[i]);
	}
	
	set <int> all;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int curr = check(a[i], b[j]);
			if (curr != -1)
				all.insert(curr);
		}
	
	if (all.size() == 1) {
		printf("%d\n", *all.begin());
		return 0;
	}
	
	bool ok = true;
	for (int i = 0; i < N; i++) {
		set <int> tmp;
		for (int j = 0; j < M; j++) {
			int curr = check(a[i], b[j]);
			if (curr != -1)
				tmp.insert(curr);
		}
		ok &= tmp.size() <= 1;
	}
	
	for (int i = 0; i < M; i++) {
		set <int> tmp;
		for (int j = 0; j < N; j++) {
			int curr = check(b[i], a[j]);
			if (curr != -1)
				tmp.insert(curr);
		}
		ok &= tmp.size() <= 1;
	}
	
	puts(ok ? "0" : "-1");
	
	return 0;
}