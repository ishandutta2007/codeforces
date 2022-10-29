#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int V = 1e6 + 3;

int m;
ll turn = 0;
ll cnt[V], rest[V], skip[V];

int pri[V];
int mp[V], pos[V], bk[V];
void Euler(int n) {
	static bitset<V> vis;
	int num = 0;
	for (int i = 2; i <= n; i++) {
		if (!vis.test(i)) {
			mp[i] = i;
			pos[i] = 1;
			bk[i] = 1;
			pri[num++] = i;
		}
		for (int *p = pri, *_ = pri + num, x; p != _ && (x = *p * i) <= n; p++) {
			vis.set(x);
			mp[x] = *p;
			if (i % *p) {
				pos[x] = 1;
				bk[x] = i;
			} else {
				pos[x] = pos[i] + 1;
				bk[x] = bk[i];
				break;
			}
		}
	}
}

int main() {
	int maxV = 0, x;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &x);
		maxV = max(maxV, x);
		scanf("%lld", cnt + x);
	}
	scanf("%lld", &turn);
	Euler(maxV);
	for (int i = 2; i <= maxV; i++)
		rest[i] = turn;
	boolean flag = false;
	do {
		flag = false;
		for (int i = 2; i <= maxV; i++) {
			if (cnt[i]) {
				if (rest[i]) {
					ll d = min(cnt[i], rest[i]);
					cnt[i] -= d;
					rest[i] -= d;
					skip[i] += d - 1;
					flag = true;
					int x = i - 1;
					while (x > 1) {
						cnt[mp[x]] += pos[x] * d;
						x = bk[x];
					}
				}
			} else if (skip[i]) {
				skip[i]--;
			} else if (rest[i]) {
				rest[i]--;
			}
		}
	} while (flag);
	int qaq = 0;
	for (int i = 2; i <= maxV; i++) {
		if (cnt[i]) {
			qaq++;
		}
	}
	printf("%d\n", qaq);
	for (int i = 2; i <= maxV; i++) {
		if (cnt[i]) {
			printf("%d %lld\n", i, cnt[i]);
		}
	}
	return 0;
}