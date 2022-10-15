#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-17;
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int ar[10];
int used[10];
int len_ans = 0;
int anses[10];

bool check(int len){
	if(len != len_ans)
		return len > len_ans;
	for(int i = 9; i > 1; i--)
		if(used[i] != anses[i])
			return used[i] > anses[i];
	return false;
}

void dfs(int pos, int sum, int len){
	if(pos == 10){
		if(sum == 0 && check(len)){
			len_ans = len;
			for(int i = 0; i < 10; i++)
				anses[i] = used[i];
		}
		return;
	}
	for(int i = ar[pos]; i >= max(0, ar[pos] - 2); i--){
		used[pos] = i;
		dfs(pos + 1, (sum + i * pos) % 3, len + i);
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

	int n;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		ar[a]++;
	}
	if(ar[0] == 0){
		cout << -1;
		return 0;
	}
	dfs(1, 0, 0);
	for(int i = 9; i >= 0; i--){
		for(int j = 0; j < anses[i]; j++)
			cout << i;
	}
	if(len_ans == 0){
		cout << 0;
		return 0;
	}
	for(int j = 0; j < ar[0]; j++)
		cout << 0;

}