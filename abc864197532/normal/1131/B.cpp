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
	cin >> n;
	int ans=1,l=0,r=0;
	fop (i,0,n) {
		int a,b;
		cin >> a >> b;
		
		ans += max(min(a,b) - max(l,r) + 1,0);
		if (l == r) ans--;
		l = a;
		r = b;
	}
	cout << ans << endl;
}