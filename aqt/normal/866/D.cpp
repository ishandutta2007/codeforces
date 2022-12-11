
// Problem : D. Buy Low Sell High
// Contest : Codeforces - MemSQL Start[c]UP 3.0 - Round 2 and Codeforces Round #437 (Div. 1)
// URL : https://codeforces.com/contest/866/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long tot = 0;
	while(N--){
		int n;
		cin >> n;
		tot -= n;
		pq.push(n);
		pq.push(n);
		pq.pop();
	}
	while(pq.size()){
		tot += pq.top();
		pq.pop();
	}
	cout << tot;
}