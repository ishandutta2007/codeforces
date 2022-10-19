#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

int N, L, R;
int a[MAXN], b[MAXN];
bitset <MAXN> all, rest;
vector <int> imp;

void load() {
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);
}

inline int get_all() {
	return all._Find_next(L - 1);
}

inline int get_rest() {
	return rest._Find_next(L - 1);
}

int solve() {
	L++;
	R++;
	rest.set(1);
	for (int i = 0; i < N; i++)
		if (b[i])
			imp.push_back(a[i]);
		else
			rest |= rest << a[i];
	
	if (imp.empty())
		return 0;
		
	sort(imp.begin(), imp.end());
	
	int sum = 0;
	for (auto it : imp)
		sum += it;
		
	all = rest;
	int sz = imp.size();
	for (int i = sz - 1; i >= 0; i--) {
		if (get_rest() + sum <= R)
			return i + 1 + (i < sz - 1);
		if (get_all() + sum <= R)
			return i + 1;
		if (i < sz - 1)
			rest |= rest << imp[i];
		rest |= all;
		all <<= imp[i];
		all &= ~rest;
		sum -= imp[i];	
	}
	
	return get_rest() <= R;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}