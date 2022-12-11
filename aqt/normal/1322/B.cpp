
// Problem : B. Present
// Contest : Codeforces Round #626 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL : https://codeforces.com/contest/1322/problem/B
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int crr[500005];
int arr[500005];
int brr[40000000];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> crr[i];
	}
	int ans = 0;
	for(int d = 0; d<25; d++){
		long long tot = 0;
		for(int i = 1; i<=N; i++){
			arr[i] = (crr[i]&((1<<(d+1))-1));
			brr[arr[i]]++;
			tot -= !!((arr[i]<<1)&(1<<d));
		}
		partial_sum(brr, brr+(1<<(d+1)), brr);
		for(int i = 1; i<=N; i++){
			int l = (1<<d)-arr[i];
			int r = (1<<(d+1))-1-arr[i];
			tot += brr[r];
			tot -= (l > 0 ? brr[l-1] : 0);
			l = (1<<(d+1)) + (1<<d) - arr[i];
			r = (1<<(d+2)) - 1 - arr[i];
			r = min(r, (1<<(d+1))-1);
			if(l <= r){
				tot += brr[r] - brr[l-1];
			}
		}
		tot /= 2;
		//cout << d << " " << tot << "\n";
		if(tot&1){
			ans |= (1<<d);
		}
		fill(brr, brr+(1<<(d+1)), 0);
	}
	cout << ans << "\n";
}