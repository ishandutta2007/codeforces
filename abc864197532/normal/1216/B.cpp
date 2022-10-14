#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

bool bigger (pair<int,int> a, pair<int,int> b) {
	return a.first>b.first;
}

int main () {
	int n,a;
	cin >> n;
	vector <pair<int,int> > nums;
	fop (i,0,n) {
		cin >> a;
		nums.eb(a,i+1);
	}
	sort(nums.begin(),nums.end(),bigger);
	lli ans=0;
	fop (i,0,n) {
		ans+=nums[i].first*i+1;
	}
	cout << ans << endl;
	fop (i,0,n) cout << nums[i].second << ' ';
	cout << endl;
}