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
	int n,m;
	cin >> n;
	int a[n];
	fop (i,0,n) cin >> a[i];
	cin >> m;
	int b[m];
	fop (i,0,m) cin >> b[i];
	sort(a,a+n);
	sort(b,b+m);
	int ans = 0;
	for (int i = 0, j = 0; i < n && j < m;) {
		if (abs(a[i] - b[j]) <= 1) {
			ans++;
			i++;
			j++;
		} else {
			if (a[i] > b[j]) j++;
			else i++;
		}
	}
	cout << ans << endl;
}