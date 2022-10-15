#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef set<ii>::iterator sit;
typedef double ld;
typedef int** matrix;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 101;
///#define DEBUG
#else
const ll MAX = 4001;
#endif

set<ii> s1, s2;

int ans = 0;

void add(int l, int r) {
	if (l > r)
		return;
	s1.insert(make_pair(l, r));
	s2.insert(make_pair(r, l));
	ans += r - l;
}

void remove(int l, int r) {
	ans -= r - l;
	s1.erase(make_pair(l, r));
	s2.erase(make_pair(r, l));
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	string st;
	cin >> st;

	for(int i = 0; i < n; i++) {
		if(st[i] == '.') {
			int j = i;
			while(j != n - 1 && st[j + 1] == '.')
			j++;
			add(i, j);
			i = j;
		}
	}

	while(m--) {

		int a;
		char c;
		cin >> a >> c;
		a--;

		if(c == '.') {
			sit it = s2.upper_bound(make_pair(a, -1));
			if(it != s2.end() && it->second <= a && a <= it->first){
				cout << ans << endl;
				continue;
			}
			int l = a, r = a;
			it = s1.upper_bound(make_pair(a + 1, -1));
			if(it != s1.end() && it->first == a + 1){
				remove(it->first, it->second);
				r = it->second;
			}
			it = s2.upper_bound(make_pair(a - 1, -1));
			if(it != s2.end() && it->first == a - 1){
				remove(it->second, it->first);
				l = it->second;
			}
			add(l, r);
		} else {
			sit it = s2.upper_bound(make_pair(a, -1));
			if(it != s2.end() && it->second <= a && a <= it->first) {
				int l = it->second, r = it->first;
				remove(l, r);
				add(l, a - 1);
				add(a + 1, r);
			}
		}

		cout << ans << endl;

	}

}