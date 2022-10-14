#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
int MOD = 998244353;

long long modinv (int a, int b, int x, int y) {
	if (b == 0) return x;
	return modinv(b, a % b, y, x - a / b * y);
}

long long Div (int a, int b) {
	long long ans = 1ll * a * modinv(b, MOD, 1, 0) % MOD;
	return ans;
}


int main () {
	int n, tmp;
	cin >> n;
	long long summ;
	cin >> tmp;
	summ = Div(100, tmp);
	fop (i,1,n) {
		cin >> tmp;
		summ = (summ + 1)* Div(100, tmp) % MOD;
	}
	while (summ < 0) summ += MOD;
	cout << summ << endl;
}