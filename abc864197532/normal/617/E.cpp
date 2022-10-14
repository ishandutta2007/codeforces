#include <bits/stdc++.h>
using namespace std;

const int K = 350, N = 1 << 20;

struct Query {
	int l, r, id;
	bool operator < (const Query &other) {
		if (l / K != other.l / K) return l / K < other.l / K;
		return r < other.r;
	}
};

long long ans = 0;
int coun[N], k;

void add (int x) {
	ans += coun[x ^ k];
	coun[x]++;
}

void sub (int x) {
	coun[x]--;
	ans -= coun[x ^ k];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q >> k;
    int input[n], pre[n + 1];
    pre[0] = 0;
    for (int i = 0; i < n; ++i) cin >> input[i], pre[i + 1] = pre[i] ^ input[i];
	vector <Query> Q(q);
	for (int i = 0; i < q; ++i) {
		cin >> Q[i].l >> Q[i].r;
		Q[i].l--;
		Q[i].id = i;
	}
	sort(Q.begin(), Q.end());
	vector <long long> anss(q);
	int l = 0, r = -1;
	for (int i = 0; i < N; ++i) coun[i] = 0;
	for (int i = 0; i < q; ++i) {
		while (r < Q[i].r) {
			r++;
			add(pre[r]);
		}
		while (r > Q[i].r) {
			sub(pre[r]);
			r--;
		}
		while (l > Q[i].l) {
			l--;
			add(pre[l]);
		}
		while (l < Q[i].l) {
			sub(pre[l]);
			l++;
		}
		anss[Q[i].id] = ans;
	}
	for (long long i : anss) cout << i << '\n';
}