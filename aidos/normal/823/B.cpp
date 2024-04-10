#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define forit (it, s)for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FNAME "a"

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int q;
char tmp[100100];
string s;
int pos[11][100100];
vector<int> v[111];
int t[9][16][4 * 100100];

int get(char c) {
	if (c == 'A') return 0;
	if (c == 'G') return 1;
	if (c == 'C') return 2;
	if (c == 'T') return 3;
	assert(false);
}

void update(int c, int len, int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		t[c][len][v] = val;
    } else {
    	int mid = (tl + tr) >> 1;
    	if (pos <= mid) update(c, len, 2 * v, tl, mid, pos, val);
    	else update(c, len, 2 * v + 1, mid + 1, tr, pos, val);
    	t[c][len][v] = t[c][len][2 * v] + t[c][len][2 * v + 1];
    }
}

int get(int c, int len, int v, int tl, int tr, int l, int r) {
	if (l > tr || r < tl) return 0;
	if (l <= tl && tr <= r) return t[c][len][v];
	int mid = (tl + tr) >> 1;
	int ans1 = get(c, len, 2 * v, tl, mid, l, r);
	int ans2 = get(c, len, 2 * v + 1, mid + 1, tr, l, r);
	return ans1 + ans2;
}

int main () {

	#ifdef LOCAL
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif

	scanf("%s\n", tmp);
	scanf("%d\n", &q);
	n = strlen(tmp);
	s = tmp;

	for (int len = 1; len < 11; len++) {
		for (int i = 0; i < len; i++) {
			for (int j = i; j < n; j += len) v[len].pb(j);
		}
		for (int i = 0; i < v[len].size(); i++) pos[len][v[len][i]] = i;
	}

	for (int len = 1; len < 11; len++) {
		for (int i = 0; i < n; i++) {
			int c = get(s[i]);
			int p = pos[len][i];
			update(c, len, 1, 0, n - 1, p, 1);
		}
	}

	for (int iter = 0; iter < q; iter++) {
		int type;
		scanf("%d ", &type);
		if (type == 1) {
			int x;
			char cc;
			scanf("%d %c\n", &x, &cc);
			x--;
			int c = get(cc);
			int oldc = get(s[x]);
			s[x] = cc;
			for (int len = 1; len < 11; len++) {
				int p = pos[len][x];
				update(oldc, len, 1, 0, n - 1, p, 0);
				update(c, len, 1, 0, n - 1, p, 1);
			}
		} else {
			int l, r;
			string e;
			scanf("%d %d %s\n", &l, &r, tmp);
			e = tmp;
			l--; r--;
			int len = e.size();
			int ans = 0;
			int delta = l % len;
			for (int i = 0; i < len; i++) {
				int mnl = l;
				while (mnl <= r && mnl % len != (delta + i) % len) mnl++;
				if (mnl > r) continue;
				int mnr = r;
				while (mnr >= 0 && mnr % len != (delta + i) % len) mnr--;
				if (mnr < 0) continue;
				if (mnl > mnr) continue;
				int pl = pos[len][mnl];
				int pr = pos[len][mnr];
				int c = get(e[i]);
				int cur = get(c, len, 1, 0, n - 1, pl, pr);
				ans += cur;
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}