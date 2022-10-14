#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int main() {
	int n,m;
	cin >> n >> m;
	lli frac[n+1];
	frac[0] = 1;
	fop (i,1,n+1) frac[i] = frac[i-1] * i % m;
	lli ans = 0;
	fop (i,0,n) {
		ans += (frac[i+1] * frac[n-i] % m * (n - i) % m);
		ans %= m;
	}
	if (ans < 0) ans += m;
	cout << ans << endl;
}