#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;
const int mod = 998244353;

int a[maxn], m[maxn], k[maxn];
pair<int,int> b[maxn];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> m[i] >> k[i];
	ll A = 0;
	int B = 1;
	for (int t = 1; t <= 20; t++) {
		memset(a, 0, sizeof a);
		for (int j = 0; j < n; j++)
			a[m[j]] += min(t, k[j]);
		sort(a, a + maxn, greater<int>());
		ll Aa = 0;
		for (int i = 0; i < t; i++)
			Aa += a[i];
		if (Aa * B > A * t) {
			A = Aa;
			B = t;
		}
	}
	memset(a, 0, sizeof a);
	for (int j = 0; j < n; j++)
		a[m[j]] += k[j];
	sort(a, a + maxn, greater<int>());
	ll sum = 0;
	for (int i = 0; i < 20; i++)
		sum += a[i];
	for (int t = 21; t < maxn; t++) {
		sum += a[t - 1];
		if (sum * B > A * t) {
			A = sum;
			B = t;
		}
	}
	cout << B << endl;
	for (int j = 0; j < maxn; j++)
		b[j].second = j;
	for (int j = 0; j < n; j++)
		b[m[j]].first += min(B, k[j]);
	sort(b, b + maxn, greater<pair<int,int>>());
	for (int i = 0; i < B; i++)
		cout << b[i].second << " \n"[i == B-1];
}