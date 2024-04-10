#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 9;
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

const int MAX = 1002, KEY = 31;
ll hash[MAX];

ll _pow(ll n, ll m, ll MOD){
	if(m == 0)
		return 1;
	if(m == 1)
		return n;
	ll x = _pow(n, m >> 1, MOD);
	x = (x * x) % MOD;
	if(m & 1)
		x = (x * n) % MOD;
	return x;
}

int Q;

string change(string s){
	for(int i = 0; i < (int) s.size(); i++)
		if('A' <= s[i] && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	reverse(s.begin(), s.end());
	return s;
}

inline ll get_hash(string s){
	ll ans = 0;
	for(int i = 0; i < (int) s.size(); i++)
		ans = (ans * KEY + s[i] - 'a' + 1) mod;
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

	hash[0] = 1;
	for(int i = 1; i < MAX; i++)
		hash[i] = (hash[i - 1] * KEY) mod;

	Q = _pow(KEY, MOD - 2, MOD);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int m;
	cin >> m;

	int T = 1001;

	string t1[m], t2[m];
	map<int, int> tt[T];
	for(int i = 0; i < m; i++){
		cin >> t1[i];
		t2[i] = change(t1[i]);
		tt[(int) t1[i].size()][(int) get_hash(t2[i])] = i;
	}

	ll t[T];
	int from[n + 1];
	for(int i = 1; i <= n; i++)
		from[i] = -1;
	int ans[n + 1];
	ms(ans);
	from[0] = 0;
	s = "!" + s;
	ms(t);
	for(int i = 1; i <= n; i++){
		int w = s[i] - 'a' + 1;
		for(int j = min(i, 1000); j > 1; j--)
			t[j] = (t[j - 1] * KEY + w) mod;
		t[1] = w;
		for(int j = min(i, 1000); j >= 1; j--){
			map<int, int>::iterator it = tt[j].find(t[j]);
			if(it != tt[j].end() && from[i - j] != -1){
				from[i] = i - j;
				ans[i] = it->second;
				break;
			}
		}
	}

	vector<string> vec;
	int pos = n;
	while(pos){
		vec.push_back(t1[ans[pos]]);
		pos = from[pos];
	}

	for(int i = (int) vec.size() - 1; i >= 0; i--)
		cout << vec[i] << " ";

}