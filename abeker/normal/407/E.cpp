#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;
const int INF = 0x3f3f3f3f;

struct node {
	int mini, lazy;
};

int N, K, D;
int a[MAXN];
int offset;
vector <int> curr;
vector <node> t;
map <int, int> last;
int l, r, tot;

void load() {
	scanf("%d%d%d", &N, &K, &D);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

node merge(node lhs, node rhs) {
	return {min(lhs.mini, rhs.mini), lhs.lazy + rhs.lazy};
}

void prop(int x) {
	t[x].mini += t[x].lazy;
	if (x < offset) {
		t[2 * x].lazy += t[x].lazy;
		t[2 * x + 1].lazy += t[x].lazy;
	}
	t[x].lazy = 0;
}

void update(int x, int lo, int hi, int from, int to, int val) {
  prop(x);
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    t[x].mini += val;
    if (x < offset) {
      t[2 * x].lazy += val;
      t[2 * x + 1].lazy += val;
    }
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * x, lo, mid, from, to, val);
  update(2 * x + 1, mid, hi, from, to, val);
  t[x] = merge(t[2 * x], t[2 * x + 1]);
}

void update(int from, int to, int val) {
	update(1, 0, offset, from, to, val);
}

node query(int x, int lo, int hi, int from, int to) {
	prop(x);
	if (lo >= to || hi <= from)
		return {INF, 0};
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int query(int from, int to) {
	return query(1, 0, offset, from, to).mini;
}

void set(int pos, int val) {
	update(pos, pos + 1, val - query(pos, pos + 1));
}

int get(int x, int val) {
	if (x >= offset)
		return x - offset;
	prop(2 * x);
	prop(2 * x + 1);
	if (t[2 * x].mini <= val)
		return get(2 * x, val);
	return get(2 * x + 1, val);
}

void calc(vector <int> v) {
	for (auto &it : v)
		it = (it - (it % D + D) % D) / D;
		
	for (offset = 1; offset < v.size(); offset *= 2);
	t.resize(2 * offset);
	for (auto &it : t)
		it = {INF, 0};
		
	last.clear();
	for (auto it : v)
		last[it] = -1;
	
	int pos = 0;
	stack <pii> dec, inc;
	for (int i = 0; i < v.size(); i++) {
		int nxt = max(pos, last[v[i]] + 1);
		for (int j = pos; j < nxt; j++)
			set(j, INF);
		pos = nxt;
		last[v[i]] = i;
		int len = 0;
		for (; !dec.empty() && v[i] > dec.top().first; dec.pop()) {
			len += dec.top().second;
			update(i - len, i - len + dec.top().second, v[i] - dec.top().first);
		}
		dec.push({v[i], len + 1});
		len = 0;
		for (; !inc.empty() && v[i] < inc.top().first; inc.pop()) {
			len += inc.top().second;
			update(i - len, i - len + inc.top().second, inc.top().first - v[i]);
		}
		inc.push({v[i], len + 1});
		set(i, i);
		int left = get(1, i + K);
		if (i - left > r - l) {
			l = tot + left;
			r = tot + i;
		}
	}
}

void solve() {
	if (!D) {
		a[N] = INF;
		int pos = 0;
		for (int i = 1; i <= N; i++)
			if (a[i] != a[i - 1]) {
				if (i - pos > r - l) {
					l = pos;
					r = i;
				}
				pos = i;
			}
		printf("%d %d\n", l + 1, r);
		return;
	}
	
	curr.push_back(a[0]);
	for (int i = 1; i <= N; i++) {
		if ((a[i] - a[i - 1]) % D || i == N) {
			calc(curr);
			tot += curr.size();
			curr.clear();
		}
		curr.push_back(a[i]);
	}
	
	printf("%d %d\n", l + 1, r + 1);
}

int main() {
	load();
	solve();
	return 0;
}