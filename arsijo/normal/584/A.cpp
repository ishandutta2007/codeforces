#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".IN", "r", stdin); freopen(x ".OUT", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
#ifdef LOCAL
typedef double ld;
#else
typedef double ld;
#endif
typedef vector<int>::iterator vit;
typedef pair<ld, int> li;
const ld E = 1e-8;
typedef unsigned short int usi;

#ifdef LOCAL
const int MAX = 1e4;
#else
const int MAX = 3e4 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	if(n == 1 && m == 10){
		cout << -1;
		return 0;
	}

	if(m == 10){
		m = 1;
	}
	cout << m;
	while(--n)
		cout << 0;

}