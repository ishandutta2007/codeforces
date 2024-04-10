#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, tmp, all = 0, aa = 0;
		cin >> n;
		fop (i,0,n) {
			cin >> tmp;
			all += tmp;
			if (tmp & 1) aa |= 1;
			else aa |= 2;
		}
		if (all % 2 == 0 and aa != 3) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}