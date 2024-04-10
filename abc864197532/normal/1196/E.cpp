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
		int b,w;
		cin >> b >> w;
		if (b > 3 * w + 1 or w > 3 * b + 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		int k = 3;
		if (b > w) k = 2, swap(b,w);
		fop (i,0,b) {
			cout << k << ' ' << 2 * (i + 1) << endl;
		}
		fop (i,0,b+1) {
			if (w == 0) break;
			cout << k << ' ' << 2 * i + 1 << endl;
			w--;
		}
		if (w == 0) continue;
		fop (i,0,b) {
			if (w == 0) break;
			cout << k - 1 << ' ' << 2 * (i + 1) << endl;
			w--;
		}
		if (w == 0) continue;
		fop (i,0,b) {
			if (w == 0) break;
			cout << k + 1 << ' ' << 2 * (i + 1) << endl;
			w--;
		}
	}
}