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
	lli k,b;
	cin >> n >> k;
	b = k;
	int a[n];
	fop (i,0,n) a[i] = i + 1;
	lli ans=0;
	k -= 1ll * n * (n+1) / 2;
	if (k < 0) {
		cout << -1 << endl;
		return 0;
	}
	lli sum=0;
	fop (i,0,n/2) sum += n - i;
	sum *= 2;
	if (n % 2) sum += (n + 1) / 2;
	if (b >= sum) {
		cout << sum << endl;
		fop (i,0,n) cout << i + 1 << ' ';
		cout << endl;
		fop (i,n,0) cout << i + 1 << ' ';
		cout << endl;
		return 0;
	}
	int now;
	vector <int> nums;
	fop (i,0,n/2) {
		if (k >= n - i * 2 - 1) {
			k -= n - i * 2 - 1;
			a[i] += n - i * 2 - 1;
			nums.pb(a[i]);
		} else {
			a[i] += k;
			k = 0;
			now = i + 1;
			nums.pb(a[i]);
			break;
		}
	}
	sort(nums.begin(),nums.end());
	int noww=0,nowww=1;
	fop (i,now,n) {
		while (noww < n && nums[noww] == nowww) noww++, nowww++;
		a[i] = nowww;
		nowww++;
	}
	cout << b << endl;
	fop (i,0,n) cout << i + 1 << ' ';
	cout << endl;
	fop (i,0,n) cout << a[i] << ' ';
	cout << endl;
}