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
#define y1 asd
#define left asdleft
#define right asdright
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-7;
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

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
//output;
#else

#endif

	int n, m;
	cin >> n >> m;
	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);
	set<ii> s;
	for(int i = 0; i < n; i++)
		s.insert(make_pair(ar[i], i));
	s.insert(make_pair(INT_MAX, n));
	while(m--){
		int b;
		cin >> b;
		cout << s.upper_bound(make_pair(b, INT_MAX))->second << " ";
	}

}