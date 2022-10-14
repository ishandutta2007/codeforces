#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1000, logN = 17;

set <string> all, now_pos;

int compare(string s, string t) {
	int a = 0, b = 0;
	fop (i,0,4) {
		bool is = true;
		if (s[i] == t[i]) {
			a++;
		} else {
			fop (j,0,4) {
				if (s[i] == t[j]) {
					b++;
					break;
				}
			}
		}
	}
	//9041
	return a * 10 + b;
}

int ask (string s) {
	vector <int> tmp(100, 0);
	for (string t : now_pos) {
		tmp[compare(t, s)]++;
	}
	return *max_element(all(tmp));
}

int main () {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    fop (i,0,10000) {
    	string aa = to_string(i);
    	if (aa.size() < 4) aa = '0' + aa;
    	sort(all(aa));
    	if (unique(all(aa)) - aa.begin() == 4) {
    		do {
    			all.insert(aa);
    			now_pos.insert(aa);
			} while (next_permutation(all(aa))); 
		}
	}
	int a, b;
	while (now_pos.size() > 1) {
		string now = "";
		int cnt = x;
		for (string s : all) {
			int k = ask(s);
			if (cnt > k) {
				now = s;
				cnt = k;
			}
		}
		cout << now << endl;
		cin >> a >> b;
		if (a == 4 && b == 0) {
			return 0;
		}
		vector <string> del;
		for (string s : now_pos) {
			if (compare(s, now) != a * 10 + b) {
				del.pb(s);
			}
		}
		for (string s : del) now_pos.erase(s);
	}
	cout << *now_pos.begin() << endl;
	cin >> a >> b;
	assert(a == 4 && b == 0);
	return 0;
}