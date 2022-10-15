#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-8;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

inline int get(int a) {
	return a >= 2 ? 1 : 0;
}

void test() {
	ofstream cout("input.txt");
	srand(time(NULL));
	int n = rand() % 30 + 10;
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << (rand() % 2) << " ";
	}
	cout.close();
}

int make(int n, int *ar, int l, int r) {
	if (l == r)
		return 0;
	if (ar[l] == ar[r]) {
		for (int i = l + 1; i < r; i++)
			ar[i] = ar[l];
	} else {
		for (int i = l + 1; i < r; i++)
			ar[i] = (abs(i - l) < abs(r - i) ? ar[l] : ar[r]);
	}
	return (r - l) / 2;
}

void solve_quick(int n, int *ar) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l = i;
		while (i != n - 1 && ar[i + 1] != ar[i])
			i++;
		ans = max(ans, make(n, ar, l, i));
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << ar[i] << " ";
	cout << endl;
}

int main() {

	test();

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int ar[n];
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	if (0) {
		for (int i = 0; i < n; i++)
			cout << ar[i] << " ";
		cout << endl;
	}
	int q[n];
	for (int i = 0; i < n; i++)
		q[i] = ar[i];

	solve_quick(n, q);
	return 0;
	deque<int> d;
	for (int i = 1; i < n - 1; i++)
		d.push_back(i);

	int ans = 0;

	while (true) {
		int size = (int) d.size();
		deque<ii> dd;
		for (int i = 0; i < size; i++) {
			int q = d.front();
			d.pop_front();
			for (int j = -1; j <= 1; j += 2) {
				int pos = q + j;
				if (pos != 0 && pos != n - 1
						&& get(ar[pos - 1] + ar[pos] + ar[pos + 1])
								!= ar[pos]) {
					dd.push_back(make_pair(pos, 1 - ar[pos]));
				}
			}
		}
		if (dd.empty())
			break;
		ans++;
		while (!dd.empty()) {
			if (ar[dd.front().first] != dd.front().second) {
				d.push_back(dd.front().first);
				ar[dd.front().first] = dd.front().second;
			}
			dd.pop_front();
		}
		if (0) {
			for (int i = 0; i < n; i++)
				cout << ar[i] << " ";
			cout << endl;
		}
	}

	int res = 0;
	for (int i = 1, q = 1; i < n; i++) {

	}

	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << ar[i] << " ";

}