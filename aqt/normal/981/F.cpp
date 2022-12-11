
// Problem : F. Round Marriage
// Contest : Codeforces - Avito Code Challenge 2018
// URL : https://codeforces.com/contest/981/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long L;
long long a[200005], b[200005];
long long d[200005];

bool solve(long long k){
	fill(d, d+1+N, 0);
	//cout << k << "\n";
	for(int i = 1; i<=N; i++){
		int l, r;
		if(a[i] + k >= L){
			r = upper_bound(b+1, b+1+N, a[i] + k - L) - b - 1;
		}
		else{
			r = upper_bound(b+1, b+1+N, a[i]+k) - b - 1;
		}
		if(a[i] - k < 0){
			l = lower_bound(b+1, b+1+N, a[i] - k + L) - b;
			//cout << l << "\n";
			if(l == N+1){
				l = 1;
			}
		}
		else{
			l = lower_bound(b+1, b+1+N, a[i]-k) - b;
			if(l == N+1){
				l = 1;
			}
		}
		if(min((long long) (abs(a[i]-b[l])), (long long) (L-abs(a[i]-b[l]))) > k){
			return 0;
		}
		l -= i, r -= i;
		if(l < 0){
			l += N;
		}
		if(r < 0){
			r += N;
		}
		if(l <= r){
			d[l]++, d[r+1]--;
		}
		else{
			d[0]++, d[r+1]--;
			d[l]++, d[N]--;
		}
	}
	partial_sum(d, d+N+1, d);
	for(int i = 0; i<N; i++){
		if(d[i] == N){
			return 1;
		}
	}
	return 0;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L;
	for(int i = 1; i<=N; cin >> a[i++]);
	for(int i = 1; i<=N; cin >> b[i++]);
	sort(a+1, a+1+N);
	sort(b+1, b+1+N);
	int l = 0, r = L/2, ans = L;
	while(l <= r){
		int mid = l+r>>1;
		if(solve(mid)){
			ans = mid;
			r = mid-1;
		}
		else{
			l= mid+1;
		}
	}
	cout << ans;
}