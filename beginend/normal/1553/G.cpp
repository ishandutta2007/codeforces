#include<bits/stdc++.h>
using namespace std;

const int N = 150005;
const int S = 1000005;

int n, q, prime[S], tot, lst[S], a[N], fa[N + S];
bool not_prime[S];
vector<int> edge[N + S];

void get_prime(int n) {
	for (int i = 2; i <= n; i++) {
		if (!not_prime[i]) prime[++tot] = i, lst[i] = tot;
		for (int j = 1; j <= tot && i * prime[j] <= n; j++) {
			not_prime[i * prime[j]] = 1;
			lst[i * prime[j]] = j;
			if (i % prime[j] == 0) break;
		}
	}
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[find(x)] = find(y);
}

int main() {
	get_prime(1000001);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= tot + n; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int tmp = a[i];
		while (tmp > 1) {
			merge(lst[tmp], i + tot);
			int p = prime[lst[tmp]];
			while (tmp % p == 0) tmp /= p;
		}
	}
	for (int i = 1; i <= n; i++) {
		int tmp = a[i] + 1;
		vector<int> vec;
		vec.push_back(find(i + tot));
		while (tmp > 1) {
			vec.push_back(find(lst[tmp]));
			int p = prime[lst[tmp]];
			while (tmp % p == 0) tmp /= p;
		}
		for (int j = 0; j < vec.size(); j++)
			for (int k = j + 1; k < vec.size(); k++)
			{
				int x = vec[j], y = vec[k];
				if (x > y) swap(x, y);
				edge[x].push_back(y);
			}
	}
	for (int i = 1; i <= tot + n; i++)
		sort(edge[i].begin(), edge[i].end());
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		x = find(x + tot); y = find(y + tot);
		if (x == y) printf("%d\n", 0);
		else {
			if (x > y) swap(x, y);
			if (binary_search(edge[x].begin(), edge[x].end(), y)) printf("%d\n", 1);
			else printf("%d\n", 2);
		}
	}
	return 0;
}