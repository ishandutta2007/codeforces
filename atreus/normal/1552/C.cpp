#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200 + 10;

pair<int,int> p[maxn];
bool mark[maxn];

bool isbetween(int l, int r, int x) {
	if (l > r)
		swap(l, r);
	return l < x && x < r;
}

bool isect(int a, int b, int x, int y) {
	return isbetween(a, b, x) ^ isbetween(a, b, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= 2*n; i++)
			mark[i] = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			mark[x] = mark[y] = 1;
			p[i] = {x,y};
		}
		vector<int> a;
		for (int i = 1; i <= 2*n; i++)
			if (!mark[i])
				a.push_back(i);
		int tmp = k;
		for (int i = 0; i < n - k; i++)
			p[tmp++] = {a[i], a[i + n - k]};
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				cnt += isect(p[i].first, p[i].second, p[j].first, p[j].second);
		cout << cnt << endl;
	}
}