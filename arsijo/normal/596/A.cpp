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
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-10;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int s(int x1, int y1, int x2, int y2){
	cout << (x2 - x1) * (y2 - y1);
	exit(0);
}

void no(){
	cout << "-1";
	exit(0);
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	if(n == 1)
		no();

	set<int> s1, s2;

	int x[n], y[n];
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		s1.insert(x[i]);
		s2.insert(y[i]);
	}

	if(n == 2){
		if(x[0] == x[1] || y[0] == y[1])
			no();
	}

	s(*s1.begin(), *s2.begin(), *s1.rbegin(), *s2.rbegin());

}