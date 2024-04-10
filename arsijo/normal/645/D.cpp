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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 1e5;
ii t[MAX], ar[MAX];
int down[MAX];
bool used1[MAX];
int used2[MAX];
vector<int> vec[MAX];
int n;

int dfs(int pos){
	if(used1[pos])
		return down[pos];
	int ans = 0;
	used1[pos] = true;
	for(int i = 0; i < (int) vec[pos].size(); i++){
		ans = max(ans, dfs(vec[pos][i]));
	}
	return down[pos] = ans + 1;
}

int check(int n){
	for(int i = 0; i < MAX; i++)
		vec[i].clear();
	for(int i = 0; i < n; i++)
		vec[ar[i].first].push_back(ar[i].second);
	ms(used1);
	for(int i = 0; i < ::n; i++)
		if(dfs(i) == ::n)
			return true;
	return false;
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

	int m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		cin >> ar[i].first >> ar[i].second;
		ar[i].first--, ar[i].second--;
	}

	if(!check(m)){
		cout << -1;
		return 0;
	}

	int l = 1, r = m;
	while(l < r){
		int x = (l + r) >> 1;
		if(check(x)){
			r = x;
		}else{
			l = x + 1;
		}
	}

	cout << l;

}