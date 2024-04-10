#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>


int main () {
	int t;
	cin >> t;
	while (t--) {
		lli r,b,k;
		cin >> r >> b >> k;
		lli g = __gcd(r, b);
		r /= g;
		b /= g;
		lli a1 = r - 1, a2 = b - 1;
		if (a1 < a2) swap(a1, a2);
		lli aa = a1 / (a2 + 1);
		if (a1 % (a2 + 1)) aa++;
		if (aa >= k) cout << "REBEL" << endl;
		else cout << "OBEY" << endl;
	}
}