#include <bits/stdc++.h>
using namespace std;

const int K = 350;

struct Block {
	deque <int> a;
	vector <int> count;
	Block (int all) {
		count.resize(all, 0);
	}
	void print() {
		for (int i = 0; i < a.size(); ++i) cout << a[i] << ' ';
		cout << '\n';
	}
};

int ask (deque <int> &dq, int l, int r, int k) {
	vector <int> tmp;
	int ans = 0;
	while (dq.size()) {
		tmp.push_back(dq.front());
		dq.pop_front();
	}
	for (int i = l; i <= r; ++i) {
		if (tmp[i] == k) ans++;
	}
	while (tmp.size()) {
		dq.push_front(tmp.back());
		tmp.pop_back();
	}
	return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, tmp;
    cin >> n;
    vector <Block> b;
    vector <int> input(n);
	for (int i = 0; i < n; ++i) cin >> input[i], input[i]--;
	b.push_back(Block(n));
	for (int i = 0; i < n; ++i) {
		if (b.back().a.size() == K) b.push_back(Block(n));
		b.back().a.push_back(input[i]);
		b.back().count[input[i]]++;
	}
	int t, l, r, k, ans = 0;
	cin >> q;
	while (q--) {
		cin >> t >> l >> r;
		l = (l + ans - 1) % n;
		r = (r + ans - 1) % n;
		if (l > r) swap(l, r);
		if (t == 2) {
			cin >> k;
			k = (k + ans - 1) % n;
			ans = 0;
			if (l / K == r / K) {
				ans += ask(b[l / K].a, l % K, r % K, k);
			} else {
				ans += ask(b[l / K].a, l % K, K - 1, k);
				for (int i = l / K + 1; i < r / K; ++i) ans += b[i].count[k];
				ans += ask(b[r / K].a, 0, r % K, k);
			}
			cout << ans << '\n';
		} else {
			int ll = l % K, rr = r % K;
			if (l / K == r / K) {
				rotate(b[l / K].a.begin() + ll, b[l / K].a.begin() + rr, b[l / K].a.begin() + rr + 1);
			} else {
				rotate(b[l / K].a.begin() + ll, b[l / K].a.end() - 1, b[l / K].a.end());
				for (int i = l / K + 1; i < r / K; ++i) {
					b[i].a.push_front(b[i].a.back());
					b[i].a.pop_back();
				}
				rotate(b[r / K].a.begin(), b[r / K].a.begin() + rr, b[r / K].a.begin() + rr + 1);
				for (int i = r / K; i > l / K + 1; --i) {
					b[i].count[b[i].a.front()]--;
					b[i - 1].count[b[i - 1].a.front()]--;
					swap(b[i].a[0], b[i - 1].a.front());
					b[i].count[b[i].a.front()]++;
					b[i - 1].count[b[i - 1].a.front()]++;
				}
				b[l / K + 1].count[b[l / K + 1].a.front()]--;
				b[l / K].count[b[l / K].a[ll]]--;
				swap(b[l / K + 1].a.front(), b[l / K].a[ll]);
				b[l / K + 1].count[b[l / K + 1].a.front()]++;
				b[l / K].count[b[l / K].a[ll]]++;
			}
		}
		//b[0].print();
	}
}