#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
template<typename T> inline T sqr(T a) {
	return a * a;
}
#define endl "\n"
#define def(f) make(#f);
#define y1 dads
typedef long long ll;
typedef unsigned long long ull;
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
const ld E = 1e-15;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

set<iii> s;

set<char> sett;

void solve(int a, int b, int c){
	if(s.find(make_pair(make_pair(a, b), make_pair(c, 0))) == s.end()){
		s.insert(make_pair(make_pair(a, b), make_pair(c, 0)));
		if(a == 0 && b == 0){
			sett.insert('R');
			return;
		}
		if(a == 0 && c == 0){
			sett.insert('G');
			return;
		}
		if(b == 0 && c == 0){
			sett.insert('B');
			return;
		}
		if(a >= 2)
			solve(a - 1, b, c);
		if(b >= 2)
			solve(a, b - 1, c);
		if(c >= 2)
			solve(a, b, c - 1);
		if(a && b)
			solve(a - 1, b - 1, c + 1);
		if(a && c)
			solve(a - 1, b + 1, c - 1);
		if(b && c)
			solve(a + 1, b - 1, c - 1);
	}
}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	string s;
	cin >> s;

	int a = 0, b = 0, c = 0;
	for(int i = 0; i < (int) s.size(); i++){
		if(s[i] == 'B')
			a++;
		if(s[i] == 'G')
			b++;
		if(s[i] == 'R')
			c++;
	}

	solve(a, b, c);
	for(set<char>::iterator it = sett.begin(); it != sett.end(); it++)
		cout << *it;

}