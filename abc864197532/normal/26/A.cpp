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
	set <int> prime[3001];
	fop (i,2,3001) {
		if (prime[i].size() == 0) {
			for (int j = i; j < 3001; j += i) {
				prime[j].insert(i);
			}
		}
	}
	int ans = 0;
	fop (i,2,n+1) {
		if (prime[i].size() == 2) {
			ans++;
		}
	}
	cout << ans << endl;
}