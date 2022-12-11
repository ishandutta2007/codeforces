
// Problem : C. Sonya and Problem Wihtout a Legend
// Contest : Codeforces - Codeforces Round #371 (Div. 1)
// URL : https://codeforces.com/contest/713/problem/C
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	priority_queue<int> pq;
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		n -= i;
		pq.push(n);
		pq.push(n);
		ans += abs(pq.top()-n);
		pq.pop();
	}
	cout << ans << "\n";
}