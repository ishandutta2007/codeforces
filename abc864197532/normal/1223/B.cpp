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
		string a,b;
		cin >> a >> b;
		int c[26],d[26];
		fop (i,0,26) {
			c[i]=0;
			d[i]=0;
		}
		fop (i,0,a.length()) {
			c[a[i]-'a']=1;
		}
		fop (i,0,b.length()) {
			d[b[i]-'a']=1;
		}
		bool is=false;
		fop (i,0,26) {
			if (d[i] && c[i]) {
				is=true;
			}
		}
		if (is) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}