
// Problem : D. Rsum Review
// Contest : Codeforces - Codeforces Round #639 (Div. 1)
// URL : https://codeforces.com/contest/1344/problem/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
long long arr[100005];
long long out[100005];
priority_queue<pair<long long, pair<int, int>>> pq;

long long calc(long long a, long long b){
	return -3*b*b + 3*b - 1 + a;
}

long long solve(long long k, bool b = 0){
	long long ret = 0;
	for(int i = 1; i<=N; i++){
		long long l = 1, r = arr[i], idx = 0;
		while(l <= r){
			long long mid = l+r>>1;
			if(calc(arr[i], mid) >= k){
				idx = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		ret += idx;
		if(b){
			out[i] = idx;
			if(out[i] != arr[i]){
				//cout << i << " " << calc(arr[i], out[i]+1) << "\n";
				pq.push({calc(arr[i], out[i]+1), {out[i]+1, i}});
			}
		}
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	long long l = -4e18, r = 4e18, ans = 0;
	while(l <= r){
		long long mid = l+r>>1;
		if(solve(mid) <= K){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	long long tot = solve(ans, 1);
	assert(K-tot <= 3*N);
	//cout << K-tot << "\n";
	while(tot < K){
		auto p = pq.top();
		pq.pop();
		out[p.second.second] = p.second.first;
		if(out[p.second.second] != arr[p.second.second]){
			pq.push({calc(arr[p.second.second], p.second.first+1), {p.second.first+1, p.second.second}});
		}
		tot++;
	}
	for(int i = 1; i<=N; i++){
		cout << out[i] << " ";
	}
}