#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n;
	string s;
	cin >> n >> s;
	int a[10];
	fop (i,1,10) cin >> a[i];
	int r=-1;
	fop (i,0,n) {
		if (a[s[i]-'0']>s[i]-'0') {
			r=i;
			break;
		}
	}
	if (r==-1 and n==-1) {
		cout << s << endl;
	} else {
		fop (i,0,n) {
			if (r==i) {
				cout << a[s[i]-'0'];
				if (i+1<n and a[s[i+1]-'0']>=s[i+1]-'0') r++;
			} else {
				cout << s[i];
			}
		}
		cout << endl;
	}
}