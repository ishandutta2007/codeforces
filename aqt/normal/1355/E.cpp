
// Problem : E. Restorer Distance
// Contest : Codeforces - Codeforces Round #643 (Div. 2)
// URL : https://codeforces.com/contest/1355/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long A, B, C;
long long arr[100005];
long long pre[100005];

long long test(long long n){
	int idx = lower_bound(arr+1, arr+1+N, n) - arr - 1;
	long long cntlft = n * idx - pre[idx];
	long long cntrht = pre[N] - pre[idx] - (N - idx) * n;
	if(cntlft <= cntrht){
		return C * cntlft + B * (cntrht - cntlft);
	}
	else{
		return C * cntrht + A * (cntlft - cntrht);
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> A >> B >> C;
	C = min(A+B, C);
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N);
	partial_sum(arr, arr+1+N, pre);
	int l = 0, r = 1000000000;
	long long ans = LLONG_MAX;
	while(l <= r){
		//int optl = 1LL*(2*l+r)/3, opt2 = 1LL*(l+2*r)/3;
		int optl = l + (r-l)/3, optr = r - (r-l)/3;
		long long al = test(optl), ar = test(optr);
		ans = min({ans, al, ar});
		if(al < ar){
			r = optr - 1;
		}
		else{
			l = optl + 1;
		}
	}
	cout << ans;
}