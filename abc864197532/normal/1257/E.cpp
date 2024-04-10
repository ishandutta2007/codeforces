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
	int a,b,c;
	cin >> a >> b >> c;
	int n = a+b+c;
	int aa[a], bb[b], cc[c];
	fop (i,0,a) cin >> aa[i];
	fop (i,0,b) cin >> bb[i];
	fop (i,0,c) cin >> cc[i];
	sort(aa,aa+a);
	sort(bb,bb+b);
	sort(cc,cc+c);
	int ans[n];
	fop (i,0,a) ans[i] = aa[i];
	fop (i,0,b) ans[a+i] = bb[i];
	fop (i,0,c) ans[a+b+i] = cc[i];
	vector <int> nums;
	nums.pb(ans[0]);
	fop (i,1,n) {
		if (ans[i] > nums[nums.size()-1]) {
			nums.pb(ans[i]);
		} else {
			*lower_bound(nums.begin(), nums.end(), ans[i]) = ans[i];
		}
	}
	cout << n - nums.size() << endl;
}