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
	lli a[n];
	fop (i,0,n) cin >> a[i];
	sort(a,a+n);
	lli sum=0,all=0;
	fop (i,0,n/2) sum+=a[i];
	fop (i,n/2,n) all+=a[i];
	cout << sum*sum+all*all << endl;
}