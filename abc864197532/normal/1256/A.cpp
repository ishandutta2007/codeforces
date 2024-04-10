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
		lli a,b,n,s;
		cin >> a >> b >> n >> s;
		if (a * n + b >= s and s % n <= b) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}