#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;

int N;
vector <int> a;
vector <int> curr, opt;
int sol = MAXN;

void load() {
	scanf("%d", &N);
	a.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
}

void go(int lvl) {
	if (curr.size() >= sol)
		return;
		
	if (a.empty()) {
		if (curr.size() < sol) {
			sol = curr.size();
			opt = curr;
		}
		return;
	}
	
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	
	for (int i = -1; i < 2; i += 2) {
		vector <int> nxt;
		bool ok = false, bad = true;
		for (auto it : a) {
			bad &= it == -i;
			int tmp = it;
			if (tmp % 2) {
				tmp -= i;
				ok = true;
			}
			if (tmp)
				nxt.push_back(tmp / 2);
		}
		if (bad)
			continue;
		vector <int> memo = a;
		a = nxt;
		if (ok)
			curr.push_back((1 << lvl) * i);
		go(lvl + 1);
		if (ok)
			curr.pop_back();
		a = memo;
	}
}

void solve() {
	go(0);
	
	printf("%d\n", sol);
	for (auto it : opt)
		printf("%d ", it);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}