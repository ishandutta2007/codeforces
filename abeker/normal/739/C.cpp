#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int offset = 1 << 19;

struct node {
	int sol, len, one, zero, pref, suff;
};

int N, M;
ll a[offset];
int sgn[offset];
node t[2 * offset];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", a + i);
}            

void refresh(int x) {
	if (a[x] < 0)
		sgn[x] = 0;
	else if (a[x] > 0)
		sgn[x] = 1;
	else
		sgn[x] = -1;
	if (x < 1 || x >= N)
		sgn[x] = -1;
	t[x + offset] = {sgn[x] != -1, 1, sgn[x] == 1, sgn[x] == 0, sgn[x] != -1, sgn[x] != -1};
}

node merge(node l, node r) {
	node res;
	res.sol = max(max(l.sol, r.sol), max(l.suff + r.one, l.zero + r.pref));
	res.len = l.len + r.len;
	res.one = l.one + (l.one == l.len ? r.one : 0);
	res.zero = r.zero + (r.zero == r.len ? l.zero : 0);
	res.pref = max(l.pref + (l.pref == l.len ? r.one : 0), l.zero == l.len ? l.zero + r.pref : 0);
	res.suff = max(r.suff + (r.suff == r.len ? l.zero : 0), r.one == r.len ? r.one + l.suff : 0);
	return res;
}

void update(int x, int val) {
	a[x] += val;
	refresh(x);
	x += offset;
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}
             
void solve() {
	memset(sgn, -1, sizeof sgn);
	for (int i = 1; i < N; i++) 
		a[i] -= a[i + 1];
	for (int i = 0; i < offset; i++)
		refresh(i);
	
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
		
	scanf("%d", &M);
	while (M--) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		update(l - 1, -d);
		update(r, d);
		printf("%d\n", t[1].sol + 1);
	}
}         
          
int main() {
	load();
	solve();
	return 0;
}