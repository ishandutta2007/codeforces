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
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-10;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef LOCAL
const int MAX = 1e4 + 10;
#else
const int MAX = 2e4 + 10;
#endif
#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

	cout.precision(10);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n, p, q;
	cin >> n >> p >> q;

	int ok[n + 1];
	for(int i = 0; i <= n; i++)
		ok[i] = -1;
	ok[0] = 0;
	int t[n + 1];
	ms(t, 0);
	for(int i = 1; i <= n; i++){
		int a = (i < p ? -1 : ok[i - p]);
		int b = (i < q ? -1 : ok[i - q]);
		a = max(a, b);
		//cout << i << " " << a << " " << b << endl;
		if(a != -1){
			ok[i] = a + 1;
			t[i] = (a == b ? i - q : i - p);
		}
		//cout << i << " " << t[i] << " " << p << " " << q << endl;
	}

	string s;
	cin >> s;

	if(ok[n] == -1){
		cout << -1;
	}else{
		vector<string> v;
		int q = n;
		while(q){
			int w = t[q];
			//cout << q << " " << w << endl;
			v.push_back(s.substr(w, q - w));
			q = w;
		}

		cout << v.size() << endl;
		for(int i = (int) v.size() - 1; i >= 0; i--)
			cout << v[i] << endl;
	}


}