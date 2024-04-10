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
#ifndef LOCAL
#define endl "\n"
#endif
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

bool ar[6][6][6];

map<string, bool> m;
map<string, bool>::iterator it;

bool check(string s){
	if(s.size() == 1){
		return s[0] == 'a';
	}
	it = m.find(s);
	if(it != m.end())
		return it->second;
	int a = s[0] - 'a';
	int b = s[1] - 'a';
	bool ans = false;
	for(int i = 0; i < 6; i++){
		if(ar[a][b][i]){
			if(check(string(1, i + 'a') + s.substr(2, (int) s.size() - 2))){
				ans = true;
				break;
			}
		}
	}
	return m[s] = ans;
}

int ans = 0;

void dfs(string s, int left){
	if(left == 0){
		if(check(s))
			ans++;
		return;
	}
	for(int i = 0; i < 6; i++)
		dfs(s + string(1, i + 'a'), left - 1);
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n, m;
	cin >> n >> m;

	while(m--){
		string a, b;
		cin >> a >> b;
		ar[a[0] - 'a'][a[1] - 'a'][b[0] - 'a'] = true;
	}

	dfs("", n);

	cout << ans << endl;

}