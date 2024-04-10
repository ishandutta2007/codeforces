#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
set <int> nums[100000];
int ans[100000],n;

int main () {
	int m;
	cin >> n >> m;
	fop (i,0,m) {
		int a,b;
		cin >> a >> b;
		nums[a-1].insert(b-1);
		nums[b-1].insert(a-1);
	}
	ans[0] = 1;
	int tmp=0;
	fop (i,1,n) {
		if (nums[0].count(i)) {
			if (tmp == 0) tmp = i;
			ans[i] = 2;
		} else {
			ans[i] = 1;
		}
	}
	if (tmp == 0) {
		cout << -1 << endl;
		return 0;
	}
	set <int> c[3];
	fop (i,0,n) {
		if (nums[tmp].count(i)) {
			if (ans[i] == 2) {
				ans[i] = 3;
			}
		}
	}
	fop (i,0,n) c[ans[i]-1].insert(i);
	if (c[2].empty()) {
		cout << -1 << endl;
		return 0;
	}
	fop (i,0,3) {
    	for (int a : c[i]) {
    		for (int b : nums[a]) {
    			if (c[i].count(b)) {
    				cout << -1 << endl;
    				return 0;
    			}
    		}
    	}
	}
	fop (i,0,3) {
    	for (int a : c[i]) {
    		for (int b : c[(i+1)%3]) {
    			if (!nums[a].count(b)) {
    				cout << -1 << endl;
    				return 0;
    			}
    		}
    	}
	}
	fop (i,0,n) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}