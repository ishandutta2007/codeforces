#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int t,n;
	string s[2];
	cin >> t;
	while (t--) {
		cin >> n >> s[0] >> s[1];
		int l=0,r=0,c=0; // c 0 -- c 1 -|
		bool is=true;
		while (true) {
			if (l==n) {
				if (r==0) is=false;
				break;
			}
			if (s[r][l]>='1' and s[r][l]<='2') {
				if (c==1) {
					is=false;
					break;
				}
				c=0;
				l++;
			} else {
				if (c==0) {
					r=1-r;
					c=1;
				} else if (c==1) {
					l++;
					c=0;
				}
			}
		}
		if (is) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}