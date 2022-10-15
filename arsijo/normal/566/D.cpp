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
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 1e5 + 1;
//#define DEBUG
#else
const ll MAX = 1e6 + 1;
#endif

struct dsu {

	int *next, *t, n;

	dsu(int n){
		next = new int[n];
		t = new int[n];
		for(int i = 0; i < n; i++){
			t[i] = i;
			next[i] = i;
		}
		this->n = n;
	}

	int get(int pos){
		return (t[pos] == pos ? pos : t[pos] = get(t[pos]));
	}

	void add(int x, int y){
		if(get(x) != get(y)){
			t[get(x)] = get(y);
		}
	}

	int add2(int x, int y){
		int to = next[x];
		if(to >= y)
			return to;
		int v = to + 1;
		add(to, v);
		return next[x] = next[to] = next[v] = add2(v, y);
	}

};

int main() {

	sync;

#ifdef LOCAL
	srand(time(NULL));
	input;
#else

#endif

	int n, q;
	cin >> n >> q;

	dsu d(n);

	for(int i = 0; i < q; i++){
		int a, b, c;
		cin >> a >> b >> c;
		b--, c--;
		if(a == 1){
			d.add(b, c);
		}else if(a == 2){
			d.add2(min(b, c), max(b, c));
		}else{
			cout << (d.get(b) == d.get(c) ? "YES\n" : "NO\n");
		}
	}

}