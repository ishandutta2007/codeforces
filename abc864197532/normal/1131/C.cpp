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
	int x[n],a[n];
	fop (i,0,n) cin >> x[i];
	sort(x,x+n);
	fop (i,0,n) {
		if (i%2) {
			a[n-(i+1)/2]=x[i];
		} else {
			a[i/2]=x[i];
		}
	}
	fop (i,0,n) cout << a[i] << ' ';
	cout << endl;
}