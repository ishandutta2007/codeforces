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
		int a,b,c,d,e;
		cin >> a >> b >> c >> d >> e;
		int x=(a+c-1)/c,y=(b+d-1)/d;
		if (x+y<=e) {
			cout << x << ' ' << y << endl; 
		} else {
			cout << -1 << endl;
		}
	}
}