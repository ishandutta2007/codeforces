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
	int n, tmp, ans=0;
	cin >> n;
	set <int> nums;
	fop (i,0,n) {
		cin >> tmp;
		if (tmp > n or nums.count(tmp)) {
			ans++;
		} else {
			nums.insert(tmp);
		}
	}
	cout << ans << endl;
}