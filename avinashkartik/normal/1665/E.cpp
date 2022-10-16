#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, q, a[N];

template<typename T>
struct bitwise_trie {
	int n, b;
	stack <int> s;
	vector <T> trie;

	bitwise_trie() {}
	bitwise_trie(int n, int b) : n(n), b(b) {
		for (int i = n - 1; i >= 1; i--) s.push(i);
		trie.resize(n);
	}

	void insert(int x, int ind) {
		int v = 0;
		for (int i = b; i >= 0; i--) {
			int k = (x >> i) & 1;
			if (trie[v].go[k] == -1) {
				trie[v].go[k] = s.top();
				s.pop();
			}
			trie[v].cnt++;
			trie[v].v.pb(ind);
			v = trie[v].go[k];
		}
		trie[v].cnt++;
		trie[v].v.pb(ind);
	}

	void erase(int x) {
		int v = 0;
		for (int i = b; i >= 0; i--) {
			int k = (x >> i) & 1;
			trie[v].cnt--;
			int tmp = trie[v].go[k];
			if (trie[tmp].cnt == 1) {
				s.push(tmp);
				trie[v].go[k] = -1;
			}
			v = tmp;
		}
		trie[v].cnt--;
	}

	int min_xor(int x, int f = 0) {
		int v = 0, ans = 0;
		for (int i = b; i >= 0; i--) {
			int k = (x >> i) & 1;
			if (trie[v].go[k ^ f] != -1) {
				ans += (1 << i) * f;
				v = trie[v].go[k ^ f];
			} else {
				ans += (1 << i) * (1 ^ f);
				v = trie[v].go[k ^ 1 ^ f];
			}
		}
		return ans;
	}

	int max_xor(int x) {
		return min_xor(x, 1);
	}
	
	int query(int l, int r) {
		int v = 0;
		vector <int> p;
		for (int i = b; i >= 0; i--) {
			if (trie[v].go[0] == -1) {
				v = trie[v].go[1];
			} else {
				int ct = upper_bound(all(trie[trie[v].go[0]].v), r) - lower_bound(all(trie[trie[v].go[0]].v), l);
				if (ct == 0) {
					v = trie[v].go[1];
				} else if (ct == 1) {
					int ind = lower_bound(all(trie[trie[v].go[0]].v), l) - trie[trie[v].go[0]].v.begin();
					p.pb(trie[trie[v].go[0]].v[ind]);
					int cur_ct = upper_bound(all(trie[v].v), r) - lower_bound(all(trie[v].v), l);
					v = trie[v].go[1];
					if (cur_ct == 2) break;
				} else {
					v = trie[v].go[0];
				}
			}
		}
		int ct = upper_bound(all(trie[v].v), r) - lower_bound(all(trie[v].v), l);
		int ind = lower_bound(all(trie[v].v), l) - trie[v].v.begin();
		if (ct >= 1) p.pb(trie[v].v[ind]);
		if (ct > 1) p.pb(trie[v].v[ind]);
		int ans = INFi;
		for (int i = 0; i < p.size(); i++) {
			for (int j = i + 1; j < p.size(); j++) {
				ans = min(ans, a[p[i]] | a[p[j]]);
			}
		}
		return ans;
	}
};

struct node {
	vector <int> go = {-1, -1};
	int cnt = 0;
	vector <int> v;
};

void solve() {
	cin >> n;
	bitwise_trie <node> t(30 * n, 29);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		t.insert(a[i], i);
	}
	cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		deb1(t.query(l, r))
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}