#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
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

vector<int> get(int n){
	vector<int> v;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a)
			v.push_back(a);
	}
	int pos = 0;
	for(int i = 1; i < (int) v.size(); i++){
		if(v[i] == 1){
			pos = i;
		}
	}
	vector<int> ans;
	for(int i = 0; i < (int) v.size(); i++)
		ans.push_back(v[(i + pos) % v.size()]);
	return ans;
}

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
	vector<int> v1 = get(n);
	vector<int> v2 = get(n);
	bool ans = true;
	for(int i = 0; i < (int) v1.size(); i++){
		if(v1[i] != v2[i])
			ans = false;
	}
	cout << (ans ? "YES" : "NO") << endl;

}