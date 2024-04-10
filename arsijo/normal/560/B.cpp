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

#ifdef LOCAL
const ll MAX = 1000;
//#define DEBUG
#else
const ll MAX = 1e5 + 3;
#endif

bool check(int n, int m, ii a, ii b, ii c, ii d){
	ii ar[4] = {a, b, c, d};
	if(n > m)
		swap(n, m);
	for(int i = 0; i < 4; i++)
		if( min(ar[i].first, ar[i].second) <= n && max(ar[i].first, ar[i].second) <= m)
			return true;
	return false;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int a, b, c, d, n, m;
	cin >> n >> m >> a >> b >> c >> d;

	if(check(n, m, make_pair(a + c, max(b, d)), make_pair(max(a, c), b + d), make_pair(a + d, max(b, c)), make_pair(b + c, max(a, d)))){
		cout << "YES";
	}else{
		cout << "NO";
	}

}