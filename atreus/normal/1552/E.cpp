#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100 + 10;

bool mark[maxn];
int a[maxn * maxn], cnt[maxn * maxn];
int last[maxn];
int fi[maxn], se[maxn];

int saghf(int n, int k) {
	return (n + k - 1) / k;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n * k; i++)
		cin >> a[i];
	for (int i = 1; i <= n * k; i++) {
		if (last[a[i]] != 0 && mark[a[i]] == 0) {
			int pre = last[a[i]];
			bool flag = true;
			for (int j = pre; j <= i; j++)
				if (cnt[j] == saghf(n, k - 1))
					flag = false;
			if (flag) {
				mark[a[i]] = 1;
				fi[a[i]] = pre, se[a[i]] = i;
				for (int j = pre; j <= i; j++)
					cnt[j]++;
			}
		}
		last[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		cout << fi[i] << " " << se[i] << '\n';
}