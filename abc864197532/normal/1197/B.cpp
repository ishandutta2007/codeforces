#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int main () {
	int n;
	cin >> n;
	int a[n];
	cin >> a[0] >> a[1];
	fop (i,2,n) {
	    cin >> a[i];
	    if (a[i-2] > a[i-1] and a[i-1] < a[i]) {
	        cout << "NO" << endl;
	        return 0;
	    }
	}
	cout << "YES" << endl;
	return 0;
}