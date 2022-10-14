#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s[n];
		bool is=false;
		int a=0, b=0;
		fop (i,0,n) {
			cin >> s[i];
			if (s[i].length() % 2) is = true;
			fop (j,0,s[i].length()) {
				if (s[i][j] == '0') a++;
				else b++;
			}
		}
		if (is) {
			cout << n << endl;
		} else {
			if (a % 2 && b % 2) cout << n - 1 << endl;
			else cout << n << endl;
		}
	}
}