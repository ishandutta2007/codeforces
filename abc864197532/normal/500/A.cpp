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
	int n,t;
	cin >> n >> t;
	int a[n];
	fop (i,0,n-1) cin >> a[i];
	int i = 0;
	while (i < n - 1) {
		i += a[i];
		if (i == t - 1) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}