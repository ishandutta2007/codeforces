#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 19;

int N;
int a[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

void check(int x) {
	vector <int> v;
	for (int i = 0; i < N; i++)
		if (a[i] < 1 << x)
			v.push_back(a[i]);
	
	if (v.size() < x)
		return;
		
	vector <int> u = v;
	for (int j = 0; j < x; j++) {
		for (int i = j; i < v.size(); i++)
			if (v[i] >> j & 1) {
				swap(v[i], v[j]);
				swap(u[i], u[j]);
				break;
			}
		if (!(v[j] >> j & 1))
			return;
		for (int i = j + 1; i < v.size(); i++)
			if (v[i] >> j & 1)
				v[i] ^= v[j];
	}	
	
	vector <int> perm;
	for (int i = 0; i < x; i++) {
		vector <int> tmp = perm;
		reverse(tmp.begin(), tmp.end());
		perm.push_back(i);
		perm.insert(perm.end(), tmp.begin(), tmp.end());
	}
		
	printf("%d\n0", x);
	int pref = 0;
	for (auto it : perm) {
		pref ^= u[it];
		printf(" %d", pref);
	}
	puts("");
	exit(0);
}

void solve() {
	for (int i = LOG - 1; i; i--)	
		check(i);
	printf("0\n0\n");
}

int main() {
	load();
	solve();
	return 0;
}