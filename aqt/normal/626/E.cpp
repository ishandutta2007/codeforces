
// Problem : E. Simple Skewness
// Contest : Codeforces - 8VC Venture Cup 2016 - Elimination Round
// URL : https://codeforces.com/problemset/problem/626/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[200005];
long long pre[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N);
	partial_sum(arr, arr+1+N, pre);
	long long num = arr[1], idx = 1, den = 1;
	for(int i = 1; i<=N; i++){
		int k = 0, l = 1, r = min(i-1, N-i);
		while(l <= r){
			int mid = l+r>>1;
			if(2*(pre[N]-pre[N-mid+1]+pre[i]-pre[i-mid]) < (2*mid-1)*(arr[i-mid]+arr[N-mid+1])){
				k = mid;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		long long tempnum = pre[N] - pre[N-k] + pre[i] - pre[i-k-1];
		long long tempden = 2*k+1;
		//cout << tempnum*den - arr[i]*den*tempden << " " << num*tempden - arr[idx]*tempden*den << "\n";
		if(tempnum*den - arr[i]*den*tempden >= num*tempden - arr[idx]*tempden*den){
			num = tempnum;
			den = tempden;
			idx = i;
		}
	}
	vector<long long> ans;
	int k = (den-1)/2;
	for(int i = idx-k; i<=idx; i++){
		ans.push_back(arr[i]);
	}
	for(int i = N; i>N-k; i--){
		ans.push_back(arr[i]);
	}
	cout << den << "\n";
	for(long long n : ans){
		cout << n << " ";
	}
}