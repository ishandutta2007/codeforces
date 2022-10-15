#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1000003;
const ld E = 1e-8;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
	return (t * t)mod;
}
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[12];
int kkkk;
inline void write(int x) {
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar('\n');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n, m;
const int MAX = 4e5;
vector<int> vec[MAX];
int down[MAX], max_down[MAX], centroid[MAX], prev[MAX];

void dfs(int pos){
	down[pos] = 1;
	max_down[pos] = 0;
	for(int i = 0; i < (int) vec[pos].size(); i++){
		int to = vec[pos][i];
		dfs(to);
		down[pos] += down[to];
		max_down[pos] = max(max_down[pos], down[to]);
	}
	if(vec[pos].empty()){
		centroid[pos] = pos;
	}else{
		int max_size = down[vec[pos][0]];
		int ind = vec[pos][0];
		for(int i = 1; i < (int) vec[pos].size(); i++){
			if(down[vec[pos][i]] > max_size){
				max_size = down[vec[pos][i]];
				ind = vec[pos][i];
			}
		}
		int ans = centroid[ind];
		int s = down[pos] / 2;
		do{
			if(max_down[ans] <= s && down[pos] - down[ans] <= s)
				break;
			ans = prev[ans];
		}while(ans != pos);
		centroid[pos] = ans;
	}
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> m;
	for(int i = 2; i <= n; i++){
		int a;
		cin >> a;
		vec[a].push_back(i);
		prev[i] = a;
	}

	dfs(1);

	for(int i = 0; i < m; i++){
		int pos;
		cin >> pos;
		cout << centroid[pos] << endl;
	}

}