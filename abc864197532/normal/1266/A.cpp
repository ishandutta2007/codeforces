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

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = 0;
		bool is = false, iss = false;
		fop (i,0,s.length()) {
			ans += (s[i] - '0');
			if ((s[i] - '0') % 2 == 0 and (iss or s[i] != '0')) is = true;
			if (s[i] - '0' == 0) iss = true;
		}
		if (ans % 3 == 0 and is and iss) cout << "red" << endl;
		else cout << "cyan" << endl;
	}
}