
// Problem : D. Bear and Contribution
// Contest : Codeforces - VK Cup 2016 - Round 1
// URL : https://codeforces.com/contest/639/problem/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, X, Y;
int arr[200005];
vector<int> val[5];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> X >> Y;
	X = min(X, Y*5);
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N);
	for(int i = 1; i<=N; i++){
		for(int k = 0; k<5; k++){
			int vv = k+arr[i];
			//cout << vv << "\n";
			val[(vv%5+5)%5].push_back(vv);
		}
	}
	long long ans = LLONG_MAX/2;
	for(int k = 0; k<5; k++){
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		long long dif = 0;
		int idx = 1;
		for(auto n : val[k]){
			while(idx <= N && arr[idx] <= n){
				long long tot = 0;
				long long m = arr[idx]%5;
				m = (m+5)%5;
				long long u = arr[idx]/5;
				if(u*5 > arr[idx]){
					u--;
				}
				if(m > k){
					u++;
				}
				tot += X*u;
				tot -= (k+5-m)%5*Y;
				dif += tot;
				//cout << " " << arr[idx] << " " << n << " " << tot << "\n";
				pq.push(tot);
				idx++;
			}
			while(pq.size() > K){
				dif -= pq.top();
				pq.pop();
			}
			long long k = n/5;
			if(k*5 > n){
				k--;
			}
			if(pq.size() == K){
				//cout << n << " " << k*X << " " << dif << "\n";
				ans =min(ans, k*X*K-dif);
			}
		}
	}
	cout << ans;
}