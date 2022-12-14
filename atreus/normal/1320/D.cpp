#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;

string s;
int pw[maxn], par[maxn];

struct node{
	int cnt1;
	int cnt0;
	int hsh;
	node(){
		cnt0 = cnt1 = hsh = 0;
	}
} seg[4 * maxn];

node merge(node s, node t){
	node ret;
	ret.cnt0 = s.cnt0 + t.cnt0;
	ret.cnt1 = s.cnt1 + t.cnt1;
	int A = 1ll * s.hsh * pw[t.cnt0] % mod;
	if (s.cnt1 & 1)
		t.hsh = (pw[t.cnt0] - t.hsh - 1 + mod) % mod;
	int B = t.hsh;
	ret.hsh = (A + B) % mod;
	return ret;
}

node get(int id, int L, int R, int l, int r){
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	if (mid <= l)
		return get(2 * id + 1, mid, R, l, r);
	if (r <= mid)
		return get(2 * id + 0, L, mid, l, r);
	return merge(get(2 * id + 0, L, mid, l, r), get(2 * id + 1, mid, R, l, r));
}

void build(int id, int L, int R){
	if (L + 1 == R){
		if (s[L] == '1')
			seg[id].cnt1 ++;
		else
			seg[id].cnt0 ++;
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	seg[id] = merge(seg[2 * id + 0], seg[2 * id + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		par[i + 1] = par[i] + (s[i] == '1');
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = 2ll * pw[i - 1] % mod;
	build(1, 0, n);
	int q;
	cin >> q;
	while (q --){
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		l1 --, l2 --;
		if (par[l1 + len] - par[l1] != par[l2 + len] - par[l2]){
			cout << "NO\n";
			continue;
		}
		if (get(1, 0, n, l1, l1 + len).hsh == get(1, 0, n, l2, l2 + len).hsh)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}