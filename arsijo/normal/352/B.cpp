#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-7;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
//#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
inline void read(int &n) {
	n = 0;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		n = n * 10 + ccc - '0';
	}
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

vector<int> vec[(int) 1e5 + 1];
vector<ii> ans;

inline void check(vector<int> &vec, int a){
	if(vec.empty())
		return;
	if(vec.size() == 1){
		ans.push_back(make_pair(a, 0));
		return;
	}
	int diff = vec[1] - vec[0];
	for(int i = 2; i < (int) vec.size(); i++){
		if(vec[i] - vec[i - 1] != diff)
			return;
	}
	ans.push_back(make_pair(a, diff));
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	//write();
	input;
#else

#endif

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		vec[a].push_back(i);
	}

	for(int i = 1; i <= (int) 1e5; i++)
		check(vec[i], i);

	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}

}