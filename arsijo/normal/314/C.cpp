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
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e6 + 1;
#endif

struct fenwick{

private:

	int *t, n;

public:

	fenwick(int n){
		this->n = n;
		t = new int[n];
		for(int i = 0; i < n; i++)
			t[i] = 0;
	}

	void add(int pos, int val){
		for(int i = pos; i < n; i |= (i + 1))
			t[i] = (t[i] + val) mod;
	}

	int get(int pos){
		int ans = 0;
		for(int i = pos; i >= 0; i = (i & (i + 1)) - 1)
			ans = (ans + t[i]) mod;
		return ans;
	}

};

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	fenwick f(MAX);

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		int X = f.get(x);
		f.add(x, (ll) ((ll) X * x + x + MOD - (X - f.get(x - 1) + MOD) mod) mod);
	}

	cout << f.get(MAX - 1);

}