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
	int n,k,a,tmp;
	cin >> n >> k >> a;
	int nums[n-1];
	fop (i,0,n-1) {
		cin >> tmp;
		nums[i] = tmp - a;
		a = tmp;
	}
	sort(nums,nums+n-1);
	cout << accumulate(nums,nums+n-k,0) << endl;
}