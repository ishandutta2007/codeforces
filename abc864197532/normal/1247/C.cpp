#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int gett(int n) {
    int c=0;
    while (n) {
        n/=2;
        c++;
    }
    return c;
}



int main () {
	int n,k,c=0;
	cin >> n >> k;
	if (n < 1 + k) {
	    cout << -1 << endl;
	    return 0;
	}
	while (true) {
	    n -= k;
	    c++;
	    if (n < 0) {
	        cout << -1 << endl;
	        break;
	    }
	    if (__builtin_popcount(n) <= c and gett(n) >= c) {
	        cout << c << endl;
	        break;
	    }
	}
	return 0;
}