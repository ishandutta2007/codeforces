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
	int ans=0,k;
	while (n>=10) {
		k=n%10;
		ans+=(10-k);
		n/=10;
		n++;
		while (n%10==0) {
			n/=10;
		}
	}
	cout << ans+9 << endl;
}