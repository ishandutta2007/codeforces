
// Problem : D. New Passenger Trams
// Contest : Codeforces - Codeforces Round #657 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1379/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, H, M, K;
int arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> H >> M >> K;
	M /= 2;
	for(int i = 0; i<N; i++){
		cin >> arr[i] >> arr[i];
		arr[i] %= M;
	}
	K--;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 0; i<N; i++){
		if(arr[i]+K+1 >= M){
			pq.push(make_pair(arr[i]+1, 1));
			pq.push(make_pair(arr[i]+K+1, -1));		
			pq.push(make_pair(arr[i]+M+1, 1));	
		}
		else{
			pq.push(make_pair(arr[i]+1, 1));
			pq.push(make_pair(arr[i]+K+1, -1));
			pq.push(make_pair(arr[i]+1+M, 1));
			pq.push(make_pair(arr[i]+K+M+1, -1));
		}
	}
	int tot = 0;
	while(pq.size() && pq.top().first < K){
		tot++;
		pq.pop();
	}
	int ans = INT_MAX, t = 0;
	while(pq.size()){
		int x = pq.top().first;
		while(pq.size() && pq.top().first == x){
			tot += pq.top().second;
			pq.pop();
		}
		if(ans > tot){
			ans = tot;
			t = x;
		}
		//cout << x << " " << tot << "\n";
	}
	vector<int> bad;
	t -= K;
	t %= M;
	t += M;
	t %= M;
	for(int i = 0; i<N; i++){
		if((t+K) >= M){
			if(arr[i] >= t || arr[i] < (t+K)%M){
				bad.push_back(i+1);
			}
		}
		else{
			if(t <= arr[i] && arr[i] < t+K){
				bad.push_back(i+1);
			}
		}
	}
	//cout << t << "\n";
	cout << bad.size() << " " << (t+K)%M << "\n";
	for(int n : bad){
		cout << n << " ";
	}
}