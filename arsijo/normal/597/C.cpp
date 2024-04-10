#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-10;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

#ifdef LOCAL
const int MAX = 1000;
#else
const int MAX = 2e5 + 1;
#endif

int n;

struct fenwick_tree{
	ll *t;
	fenwick_tree(){
		t = new ll[n];
		for(int i = 0; i < n; i++)
			t[i] = 0;
	}
	void add(int i, ll val){
		for(; i < n; i |= (i + 1))
			t[i] += val;
	}
	ll sum(int i){
		ll ans = 0;
		for(; i >= 0; i = (i & (i + 1)) - 1)
			ans += t[i];
		return ans;
	}
};

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int k;
	cin >> n >> k;

	fenwick_tree tree[k + 1];

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a--;
		for(int j = k; j > 0; j--)
			tree[j].add(a, tree[j - 1].sum(a - 1));
		tree[0].add(a, 1);
	}

	cout << tree[k].sum(n - 1);

}