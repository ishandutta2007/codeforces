#include <bits/stdc++.h>
#define PB push_back
using namespace std;

typedef long long int ll;
const int maxn = 2e5 + 100;
int fen[maxn], c[maxn];
ll ans;
vector <int> com, v;
map <int, bool> mark;
map <int, int> p;

int get (int ind) {
	int n = v.size();
	int ret = 0;
	for ( ; ind > 0; ind -= (ind & -ind)) {
		ret += fen[ind];
	}
	return ret;
}

void upd (int ind) {
	int n = v.size();
	for ( ; ind <= n; ind += ind & -ind) {
		fen[ind] ++;
	}
}

void find_inversion (){
	int n = v.size();
	for (int i = 0; i < n; i++)
		com.PB (c[i]);
	sort (com.begin(), com.end());
	auto it = unique (com.begin(), com.end());
	com.resize (distance (com.begin(), it));
	for (int i = 0; i < n; i++)
		c[i] = lower_bound (com.begin(), com.end(), c[i]) - com.begin() + 1;
	for (int i = 0; i < n; i++) {
		ans += get (n) - get(c[i] - 1);
		upd (c[i]);
	}
}

int main() {
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (mark[b])
			swap (a, b);
		if (mark[b]) {
			int tmp = p[a];
			p[a] = p[b];
			p[b] = tmp;
		}
		else if (mark[a]) {
			mark[b] = 1;
			v.PB (b);
			p[b] = p[a];
			p[a] = b;
		}
		else {
			mark[a] = 1;
			mark[b] = 1;
			p[a] = b;
			p[b] = a;
			v.PB (a);
			v.PB (b);
		}
	}
	sort (v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		c[i] = p[v[i]];
	find_inversion ();
//	cout << ans << endl;
	for (int i = 0; i < v.size(); i++) {
		int u = v[i];
		int w = p[u];
		int len = abs (w - u - 1);
//		cout << len << " ";
		int idx1 = lower_bound (v.begin(), v.end(), w) - v.begin();
		len -= abs (idx1 - i - 1);
//		cout << " " << idx1 << " " << i << " " << len << endl;
		ans += len;
	}
	cout << ans << endl;
}