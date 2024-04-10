#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
bool byG (pii a, pii b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second > b.second;
}

bool find (vector <pii> &nums, int k, lli a) {
	int n = nums.size(), is = 0;
	lli all = 0;
	fop (i,0,n/2+1) {
		if (nums[i].second < k) {
			all += nums[i].first;
			is++;
		} else {
			all += max(k, nums[i].first);
		}
	}
	if (all > a) return false;
	fop (i,n/2+1,n) {
		if (!is) all += nums[i].first;
		else if (nums[i].second < k) all += nums[i].first;
		else all += max(k, nums[i].first), is--;
	}
	if (is or all > a) return false;
	return true;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		lli k;
		cin >> n >> k;
		vector <pii> nums;
		fop (i,0,n) {
			int a,b;
			cin >> a >> b;
			nums.eb(a,b); 
		}
		int l = 0, r = 1e9;
		sort(nums.begin(),nums.end(),byG);
		while (r > l) {
			int m = l + r >> 1;
			if (find(nums, m, k)) l = m + 1;
			else r = m;
		}
		if (find(nums, l, k)) cout << l << endl;
		else cout << l - 1 << endl;
	}
}