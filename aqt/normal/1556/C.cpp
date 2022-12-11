
// Problem : C. Compressed Bracket Sequence
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long pre[1005];
long long arr[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		if(i % 2 == 0){
			arr[i] = -arr[i];
		}
		pre[i] = pre[i-1] + arr[i];
	}
	long long ans = 0;
	for(int i = 1; i <= N; i += 2){
		//long long mn = pre[i-1] + 1;
		long long s = arr[i];
		long long low = pre[i-1];
		long long high = pre[i] - 1;
		for(int j = i + 1; j <= N; j++){
			if(j%2 == 0){
				long long lft = max(pre[j], low);
				long long rht = min(pre[j-1]-1, high);
				//cout << i << " " << j << " " << lft << " " << rht << "\n";
				ans += max(0LL, rht - lft + 1);
			}
			s += arr[j];
			high = min(high, pre[j]);
			if(s < 0){
				break;
			}
		}
	}
	cout << ans << "\n";
}