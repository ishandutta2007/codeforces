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
		int a,b,c;
		cin >> a >> b >> c;
		int m=(a+b+c)/2;
		cout << min(max(a+c-m,0),c+1) << endl;
	}
}