#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-9;
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

ii ar[8];

bool used[8];
vector<int> v;
inline ll dist(ii a, ii b){
	return sqr(a.first - b.first) + sqr(a.second - b.second);
}
inline bool check(ii a, ii b, ii c){
	return dist(a, c) == dist(a, b) + dist(b, c);
}
void dfs(int pos){
	if(pos == 8){
		for(int i = 0; i < 4; i++){
			if(!check(ar[v[i]], ar[v[(i + 1) % 4]], ar[v[(i + 2) % 4]]) || !check(ar[v[i + 4]], ar[v[(i + 1) % 4 + 4]], ar[v[(i + 2) % 4 + 4]])){
				return;
			}
			if(dist(ar[v[0]], ar[v[1]]) != dist(ar[v[i]], ar[v[(i + 1) % 4]]))
				return;
		}
		if(dist(ar[v[4]], ar[v[5]]) != dist(ar[v[6]], ar[v[7]]) || dist(ar[v[5]], ar[v[6]]) != dist(ar[v[7]], ar[v[4]]))
			return;
		cout << "YES" << endl;
		for(int i = 0; i < 4; i++)
			cout << v[i] + 1 << " ";
		cout << endl;
		for(int i = 0; i < 4; i++)
			cout << v[i + 4] + 1 << " ";
		cout << endl;
		exit(0);
	}
	for(int i = 0; i < 8; i++)
		if(!used[i]){
			v.push_back(i);
			used[i] = true;
			dfs(pos + 1);
			used[i] = false;
			v.pop_back();
		}
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

	for(int i = 0; i < 8; i++)
		cin >> ar[i].first >> ar[i].second;

	dfs(0);
	cout << "NO" << endl;

}