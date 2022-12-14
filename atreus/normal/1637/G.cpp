#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 10;
const ll mod = 998244353;

int a[maxn];

vector<pair<int,int>> ops;
int cnt[maxn];

void op(int x, int y, int mult = 1) {
	x *= mult;
	y *= mult;
	assert(cnt[x]);
	cnt[x]--;
	assert(cnt[y]);
	cnt[y]--;
	ops.push_back({x, y});
	cnt[x+y]++;
	cnt[abs(x-y)]++;
}

void makePow2(int n, int mult) {
	if (n <= 2)
		return;
	int p = n;
	while (__builtin_popcount(p) != 1)
		p--;
	if (p == n) {
		makePow2(n - 1, mult);
		return;
	}
	for (int i = p + 1; i <= n; i++)
		op(i, p - (i - p), mult);
	makePow2(p - (n - p) - 1, mult);
	makePow2(n - p, 2 * mult);
}

void solve() {
	int n;
	cin >> n;
	if (n == 2) {
		cout << "-1\n";
		return;
	}
	for (int i = 1; i <= n; i++)
		cnt[i] = 1;	
	makePow2(n, 1);
	int x;
	for (x = 1; ; x += x)
		if (cnt[x] > 1)
			break;
	op(x, x);
	assert(cnt[0]);
	int ptr = 1;
	for (int i = 0; i <= 2 * n; i++)
		for (int j = 0; j < cnt[i]; j++)
			a[ptr++] = i;
	for (int i = 2; i <= n; i++)
		while (a[i] < n) {
			op(a[i], 0);
			op(a[i], a[i]);
			a[i] *= 2;
		}
	op(a[1], a[2]);
	cnt[a[1]] = 0;
	cout << ops.size() << '\n';
	for (auto [a,b] : ops)
		cout << a << ' ' << b << '\n';
	ops.clear();
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}