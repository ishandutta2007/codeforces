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
	int t;
	cin >> t;
	while (t--) {
		int h,n;
		cin >> h >> n;
		int a[n];
		fop (i,0,n) cin >> a[i];
		int ans=0;
		fop (i,1,n) {
			if (i == n-1) {
				ans += a[i] > 1;
				break;
			}
			if (a[i] == a[i+1] + 1) i++;
			else ans++;
		}
		cout << ans << endl;
	}
}