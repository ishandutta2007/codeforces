#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
lli MOD = 1e9+7;


int main () {
	string s;
	cin >> s;
	lli ans = 1;
	int fib[100010];
	fib[0] = 1;
	fib[1] = 1;
	fop (i,2,100010) {
		fib[i] = (fib[i-1] + fib[i-2]) % MOD;
	}
	char is=' ';
	int now = 1;
	fop (i,0,s.length()) {
		if (is == ' ') {
			if (s[i] == 'u') is = s[i];
			if (s[i] == 'n') is = s[i];
		} else {
			if (s[i] == is) now++;
			else {
				if (s[i] == 'u' or s[i] == 'n') is = s[i];
				else is = ' ';
				ans *= fib[now];
				ans %= MOD;
				now = 1;
			}
		}
		if (s[i] == 'm' or s[i] == 'w') ans = 0;
	}
	cout << (ans * fib[now])  % MOD << endl;
}