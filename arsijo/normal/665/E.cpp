#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-7;
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

const int n = (1e6 + 5) * 31;
int ar[n][2], size = 0;
int t[n];

const int Q = 30;

void add(int val){
	dbg cout << "+ " << val << endl;
	int pos = 0;
	for(int i = Q; i >= 0; i--){
		int t = (val & (1 << i)) != 0;
		if(!ar[pos][t])
			ar[pos][t] = ++size;
		dbg cout << pos << " -> " << ar[pos][t] << " " << t << endl;
		pos = ar[pos][t];
		::t[pos]++;
	}
}

ll ans = 0;

void get(int n, int k){
	int pos = 0;
	for(int i = Q; i >= 0; i--){
		int t1 = ar[pos][0], t2 = ar[pos][1];
		if(k & (1 << i)){
			swap(t1, t2);
		}
		dbg cout << t1 << " " << t2 << " " << endl;
		if(n & (1 << i)){
			dbg cout << "- " << t[t1] << endl;
			ans -= t[t1];
			pos = t2;
		}else{
			pos = t1;
		}
		dbg cout << "! " << pos << endl;
		if(!pos)
			break;
	}
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n, k;
	cin >> n >> k;

	ans = n * 1LL * (n + 1) / 2;
	int ar[n + 1];
	ar[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> ar[i];
		ar[i] ^= ar[i - 1];
	}
#ifdef LOCAL
	int _ans = 0 ;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if((ar[j] ^ ar[i - 1]) >= k){
				_ans++;
			}
		}
	}
	cout << _ans << endl;
#endif
	for(int i = n; i >= 1; i--){
		add(ar[i]);
		get(k, ar[i - 1]);
	}

	cout << ans << endl;

}