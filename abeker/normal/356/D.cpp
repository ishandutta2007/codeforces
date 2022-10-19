#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 7e4 + 5;

int N, S;
pii bag[MAXN];
bitset <MAXN> dp, prv, curr;
int st[MAXN];
bool used[MAXN];
vector <int> ch[MAXN];
int coins[MAXN];

void load() {
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", coins + i);
		bag[i] = {coins[i], i};
	}
}

void no() {
	puts("-1");
	exit(0);
}

void solve() {
	sort(bag, bag + N);
	S -= bag[N - 1].first;
	if (S < 0)
		no();
	
	prv.set(0);
	for (int i = 0; i < N - 1; i++) {
		dp = prv | (prv << bag[i].first);
		curr = dp ^ prv;
		for (int j = curr._Find_first(); j < curr.size(); j = curr._Find_next(j))
			st[j] = i;
		prv = dp;
	}
	
	if (!prv.test(S))
		no();
	
	for (; S; S -= bag[st[S]].first)
		used[st[S]] = true;
	
	int lst = N - 1;
	for (int i = N - 2; i >= 0; i--)
		if (!used[i]) {
			ch[bag[lst].second].push_back(i);
			lst = i;
		}
	
	for (int i = 0; i < N; i++) {
		for (auto it : ch[i])
			coins[i] -= bag[it].first;
		printf("%d %d", coins[i], ch[i].size());
		for (auto it : ch[i])
			printf(" %d", bag[it].second + 1);
		puts("");
	}
}

int main() {
	load();
	solve();
	return 0;
}