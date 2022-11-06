// Problem: C. Sum of Nestings
// Contest: Codeforces - 2017-2018 ACM-ICPC, NEERC, Southern Subregional Contest, qualification stage (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// Author: RedreamMer
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LL long long
#define PB push_back
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 1e5;
const int M = 100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
int read() {
	int x = 0, y = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
	for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
	return (y ? -x : x);
}

int a, b;

void print(int n, int m) {
	// cout << n << ' ' << m << endl;
	if(n < 0) return;
	while(n > m) {
		printf("()");
		--n;
	}
	printf("(");
	print(n - 1, m - n);
	printf(")");
}

signed main() {
	// freopen("in1.in", "r", stdin);
	a = read();
	b = read();
	if(a * (a - 1) / 2 < b) {
		puts("Impossible");
		return 0;
	}
	print(a - 1, b);
	return 0;
}