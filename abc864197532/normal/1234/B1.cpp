#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n,k,tmp;
	cin >> n >> k;
	vector <int> nums;
	fop (i,0,n) {
		cin >> tmp;
		if (find(nums.begin(),nums.end(),tmp)==nums.end()) {
			nums.pb(tmp);
			if (nums.size()>k) {
				nums.erase(nums.begin());
			}
		}
	}
	cout << nums.size() << endl;
	fop (i,nums.size(),0) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}