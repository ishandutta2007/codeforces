#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define y1 uandjkasd
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

void no(){
	cout << "IMPOSSIBLE";
	exit(0);
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

	int n, m, s, d;
	cin >> n >> m >> s >> d;

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);

	if(ar[0] <= s)
		no();

	int pos = 0;
	vector<ii> vec;
	for(int i = 0; i < n; i++){
		if(pos == ar[i])
			no();
		vec.push_back(make_pair(0, ar[i] - 1 - pos));
		pos = ar[i] - 1;
		int to = i;
		while(to + 1 < n && ar[to + 1] - ar[to] < s + 2)
			to++;
		int end = ar[to] + 1;
		if(end - pos > d)
			no();
		vec.push_back(make_pair(1, end - pos));
		pos = end;
		i = to;
	}

	if(pos != m)
		vec.push_back(make_pair(0, m - pos));

	for(int i = 0; i < (int) vec.size(); i++){
		cout << (vec[i].first ? "JUMP" : "RUN") << " " << vec[i].second << endl;
	}

}