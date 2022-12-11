
// Problem : E. Carrots for Rabbits
// Contest : Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1428/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long long arr[100005];
priority_queue<pair<long long, int>> pq;
int cnt[100005];

long long calc(long long n, long long k){
	long long r = n%k;
	//cout << n << " " << k << "\n";
	//cout << (n/k)*(n/k)*((k-r)) + (n/k+1)*(n/k+1)*r << "\n";
	return (n/k)*(n/k)*((k-r)) + (n/k+1)*(n/k+1)*r;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		cnt[i] = 1;
		ans += 1LL*arr[i]*arr[i];
		if(arr[i]-1){
			long long val = calc(arr[i], 1) - calc(arr[i], 2);
			pq.push(make_pair(val, i));
		}
	}
	while(pq.size() && N < K){
		auto p =pq.top();
		ans -= p.first;
		pq.pop();
		N++;
		if(cnt[p.second] == arr[p.second]){
			continue;
		}
		cnt[p.second]++;
		long long val = calc(arr[p.second], cnt[p.second]) - calc(arr[p.second], cnt[p.second] + 1);
		//cout << p.first << " " << p.second << " " << val << "\n";
		pq.push(make_pair(val, p.second));
	}
	cout << ans;
}