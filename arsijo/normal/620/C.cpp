#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-11;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
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

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int ar[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> ar[i];

	map<int, int> last;

	vector<ii> vec;
	int first = 1;

	for(int i = 1; i <= n; i++){
		if(last[ar[i]] == 0){
			last[ar[i]] = i;
		}else{
			vec.push_back(make_pair(first, i));
			first = i + 1;
			last.clear();
		}
	}

	if(vec.empty()){
		cout << -1;
		return 0;
	}

	vec.back().second = n;

	cout << vec.size() << endl;
	for(int i = 0; i < (int) vec.size(); i++)
		cout << vec[i].first << " " << vec[i].second << endl;

}