
// Problem : E. Change-free
// Contest : Codeforces - Codeforces Round #398 (Div. 2)
// URL : https://codeforces.com/contest/767/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int arr[100005];
bool tkn[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	long long tot = 0;	
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i =1; i<=N; i++){
		int c;
		cin >> c;
		K -= arr[i]%100;
		if(arr[i]%100 == 0){
			continue;
		}
		pq.push(make_pair(c*(100 - arr[i]%100), i));
		if(K < 0){
			K += 100;
			tot += pq.top().first;
			tkn[pq.top().second] = 1;
			pq.pop();
		}
	}
	cout << tot << "\n";
	for(int i= 1; i<=N; i++){
		if(tkn[i]){
			cout << (arr[i]+99)/100 << " " << 0;
		}
		else{
			cout << (arr[i])/100 << " " << arr[i]%100;
		}
		cout << "\n";
	}
}