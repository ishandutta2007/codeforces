#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n,now=1;
	cin >> n;
	vector <int> nums;
	fop (i,1,n+1) {
		if (n%i==0 && i%now==0) {
			nums.pb(i);
			now=i;
		}
	}
	fop (i,nums.size(),0) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}