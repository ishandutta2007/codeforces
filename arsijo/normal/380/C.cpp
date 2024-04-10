#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 2e5 + 1;
#endif

struct thing{
	int ans, left, right;
	thing(){
		ans = left = right = 0;
	}
	thing(int ans, int left, int right){
		this->ans = ans;
		this->left = left;
		this->right = right;
	}
	thing(thing x, thing y){
		int t = min(x.left, y.right);
		ans = x.ans + y.ans + t;
		left = x.left + y.left - t;
		right = x.right + y.right - t;
	}
};

struct segment_tree{

private:

	string s;
	int n;
	thing *t;
	vector<thing> vec;

	void build(int v, int l, int r){
		if(l == r){
			t[v] = thing(0, s[l] == '(', s[l] == ')');
			return;
		}
		int x = (l + r) >> 1;
		build(v * 2, l, x);
		build(v * 2 + 1, x + 1, r);
		t[v] = thing(t[v * 2], t[v * 2 + 1]);
	}

	void get(int v, int tl, int tr, int l, int r){
		if(tl == l && r == tr){
			vec.push_back(t[v]);
			return;
		}
		if(tr < l || r < tl)
			return;
		int x = (tl + tr) >> 1;
		get(v * 2, tl, x, l, min(x, r));
		get(v * 2 + 1, x + 1, tr, max(x + 1, l), r);
	}

public:

	segment_tree(string s){
		this->s = s;
		n = (int) s.size();
		t = new thing[n * 4];
		vec.reserve(log2(n) + 1);
		build(1, 0, n - 1);
	}

	int get(int l, int r){
		vec.clear();
		get(1, 0, n - 1, l, r);
		thing ans = vec[0];
		for(int i = 1; i < (int) vec.size(); i++)
			ans = thing(ans, vec[i]);
		return ans.ans;
	}

};

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	string s;
	cin >> s;

	segment_tree st(s);

	int n;
	cin >> n;

	while(n--){
		int l, r;
		cin >> l >> r;
		cout << st.get(l - 1, r - 1) * 2 << endl;
	}

}