#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator si;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 1001;
///#define DEBUG
#else
const ll MAX = 1e6 + 1;
#endif

int getRes(int len, int m){
	if(len < m)
		return 0;
	return ((len + 1) / (m + 1));
}

int main() {

	sync;

#ifdef LOCAL
	input;
#ifdef DEBUG
//output;
#endif
#else

#endif

	set<int> s1, s2;

	int n, m, k, q;
	cin >> n >> k >> m >> q;

	int res = getRes(n, m);
	s1.insert(n + 1);
	s2.insert(0);

	for(int i = 1; i <= q; i++){
		int x;
		cin >> x;
		int a = *s1.lower_bound(x);
		int b = -*s2.lower_bound(-x);
		s1.insert(x);
		s2.insert(-x);
		int len = a - b - 1;
	//	cout << len << endl;
		if(len >= m){
			res -= getRes(len, m);
			len = a - x - 1;
			//cout << len << endl;
			if(len >= m)
				res += getRes(len, m);
			len = x - b - 1;
			//cout << len << endl;
			if(len >= m)
				res += getRes(len, m);
		}
		if(res < k){
			cout << i;
			return 0;
		}
	}

	cout << -1;

}