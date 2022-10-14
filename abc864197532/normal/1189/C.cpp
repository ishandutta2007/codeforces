#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
 
int main () {
	int n, tmp;
	cin >> n;
	int sum[n+1];
	sum[0] = 0;
	fop (i,0,n) {
		cin >> tmp;
		sum[i+1] = sum[i] + tmp;
	}
	int m;
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << max((sum[b] - sum[a-1])/10, 0) << endl;
	}
}