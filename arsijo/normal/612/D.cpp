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
typedef pair<int, int> ii;
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

	int n, k;
	cin >> n >> k;

	vector<ii> vec;
	vec.reserve(n);
	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		vec.push_back(make_pair(l, 0));
		vec.push_back(make_pair(r, 1));
	}

	sort(vec.begin(), vec.end());

	bool ok = false;
	int l, m = 0;
	vector<ii> v;
	for(int i = 0; i < (int) vec.size(); i++){
		if(vec[i].second == 0){
			m++;
			if(m == k){
				ok = true;
				l = vec[i].first;
			}
		}else{
			if(m == k){
				v.push_back(make_pair(l, vec[i].first));
				ok = false;
			}
			m--;
		}
	}

	if(ok)
		v.push_back(make_pair(l, vec.back().first));

	cout << v.size() << endl;
	for(int i = 0; i < (int) v.size(); i++)
		cout << v[i].first << " " << v[i].second << endl;

}