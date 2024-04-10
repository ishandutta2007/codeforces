#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 2e5 + 1;
#endif

int n, m, **ar, **a, **b, X[4] = { 1, 0, -1, 0 }, Y[4] = { 0, -1, 0, 1 }, sum;
bool **used;

void pre() {
	cin >> n >> m;
	ar = new int*[n], a = new int*[n], b = new int*[n];
	used = new bool*[n];
	sum = 0;
	for (int i = 0; i < n; i++) {
		ar[i] = new int[m], a[i] = new int[m], b[i] = new int[m];
		used[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
			a[i][j] = (i == 0 ? 0 : a[i - 1][j]) + ar[i][j];
			b[i][j] = (j == 0 ? 0 : b[i][j - 1]) + ar[i][j];
		}
		sum += b[i][m - 1];
	}
}

int getSum(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		if (y1 > y2)
			swap(y1, y2);
		return (b[x1][y2] - (y1 == 0 ? 0 : b[x1][y1 - 1]));
	} else {
		if (x1 > x2)
			swap(x1, x2);
		return (a[x2][y1] - (x1 == 0 ? 0 : a[x1 - 1][y1]));
	}
}

void no() {
	cout << "-1";
	exit(0);
}

vector<int> ans;
int e, p, v;

void dfs(int x, int y, int len) {
	if (used[x][y])
		return;
	used[x][y] = true;
	p++;
	int q = 0;
	for (int i = 0; i < 4; i++) {
		int x1 = x + X[i] * len, y1 = y + Y[i] * len;
		if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m
				|| getSum(x + X[i], y + Y[i], x + X[i] * len, y + Y[i] * len)
						!= len)
			continue;
		q++, v++;
		dfs(x1, y1, len);
	}
	if (q & 1)
		e++;
}

bool check(int x, int y, int len) {
	//cout << "check " << len << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			used[i][j] = false;
	e = 0;
	p = 0;
	v = 0;
	dfs(x, y, len);
	if (e > 2)
		return false;
	int res = p + (v >> 1) * (len - 1);
	//cout << e << " " << p << " " << v << " " << res << endl;
	return (res == sum);
}

int getMax() {
	int a[n][m], b[n][m];
	ms(a);
	ms(b);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ar[i][j]) {
				a[i][j] = 1 + (i == 0 ? 0 : a[i - 1][j]);
				b[i][j] = 1 + (j == 0 ? 0 : b[i][j - 1]);
				ans = max(ans, max(a[i][j], b[i][j]));
			}
		}
	}
	return ans;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	pre();

	int x = -1, y;

	for(int i = 0; i < n && x == -1; i++)
	for(int j = 0; j < m; j++)
	if(ar[i][j]) {
		x = i, y = j;
		break;
	}

	if(x == -1)
	no();

	int r = getMax() - 1;
	if(r <= 1)
		no();
	//cout << r << " " << sum << endl;
	for(int i = 2; i <= (int) sqrt(r); i++) {
		if(r % i == 0) {
			if(check(x, y, i))
			ans.push_back(i);
			if(i * i != r && check(x, y, r / i))
			ans.push_back(r / i);
		}
	}
	if(check(x, y, r)) {
		ans.push_back(r);
	}

	if(ans.empty())
	no();

	sort(ans.begin(), ans.end());
	for(int i = 0; i < (int) ans.size(); i++) {
		if(i == 0 || ans[i] != ans[i - 1]) {
			cout << ans[i] << " ";
		}
	}

}