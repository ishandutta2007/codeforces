#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N, M;
int a[MAXN], b[MAXN];
vector <int> comp;
set <int> S[MAXN];
int tot[MAXN], cnt[MAXN];
pii num[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);
	scanf("%d", &M);
}

int get(int val) {
	return lower_bound(comp.begin(), comp.end(), val) - comp.begin();
}

pii calc(int x) {
	int res = 0;
	for (; !(x % 2); x /= 2)
		res++;
	return {x, res};
}

inline int mul(int x, int y) {
	return (long long)x * y % M;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int solve() {
	for (int i = 0; i < N; i++) {
		comp.push_back(a[i]);
		comp.push_back(b[i]);
	}
	sort(comp.begin(), comp.end());
	for (int i = 0; i < N; i++) {
		a[i] = get(a[i]);
		b[i] = get(b[i]);
	}
	
	for (int i = 0; i < N; i++) {
		cnt[a[i]] += S[a[i]].count(i);
		S[a[i]].insert(i);
		tot[a[i]]++;
		cnt[b[i]] += S[b[i]].count(i);
		S[b[i]].insert(i);	
		tot[b[i]]++;
	}
	
	for (int i = 1; i < MAXN; i++)
		num[i] = calc(i);
	
	int sol = 1, exp = 0;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 1; j <= tot[i]; j++) {
			sol = mul(sol, num[j].first);
			exp += num[j].second;
		}
		exp -= cnt[i]; 
	}
	
	return mul(sol, pot(2, exp));
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}