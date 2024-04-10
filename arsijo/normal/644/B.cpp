#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define y1 ybutnot1
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

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n, b;
	cin >> n >> b;

	vector<iii> vec(n);
	for(int i = 0; i < n; i++) {
		cin >> vec[i].first.first >> vec[i].first.second;
		vec[i].second = i;
	}

	ll ar[n];
	for(int i = 0; i < n; i++) {
		ar[i] = -1;
	}

	queue<iii> q;
	ll pos = 0;
	for(int i = 0; i < n; i++) {
		while(!q.empty() && pos + q.front().first.second <= vec[i].first.first) {
			pos += q.front().first.second;
			ar[q.front().second] = pos;
			q.pop();
		}
		if(q.empty()) {
			q.push(vec[i]);
			pos = q.front().first.first;
		} else if((int) q.size() <= b){
			q.push(vec[i]);
		}
	}

	while(!q.empty()){
		pos += q.front().first.second;
		ar[q.front().second] = pos;
		q.pop();
	}

	for(int i = 0; i < n; i++){
		cout << ar[i] << " ";
	}

}