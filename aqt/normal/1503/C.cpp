
// Problem : C. Travelling Salesman Problem
// Contest : Codeforces - Codeforces Round #712 (Div. 1)
// URL : https://codeforces.com/contest/1503/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int dsu[100005];
long long arr[100005];
long long crr[100005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	iota(dsu, dsu + 1 + N, 0);
	//priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pqac, pqa;
	priority_queue<pair<long long, int>> pqac, pqa;
	for(int i = 1; i <= N; i++){
		cin >> arr[i] >> crr[i];		
		pqac.push(make_pair(arr[i] + crr[i], i));
		pqa.push(make_pair(arr[i], i));
	}
	swap(pqac, pqa);
	long long ans = 0;
	while(pqac.size() > 1){
		auto p = pqac.top();
		pqac.pop();
		if(getrt(p.second) == getrt(pqa.top().second)){
			auto t = pqa.top();
			pqa.pop();
			auto q = pqa.top();
			pqa.pop();
			ans += max(q.first, p.first);
			pqa.push(t);
			dsu[getrt(p.second)] = dsu[getrt(q.second)];
		}
		else{
			auto q = pqa.top();
			pqa.pop();
			ans += max(q.first, p.first);
			dsu[getrt(p.second)] = dsu[getrt(q.second)];
		}
	}
	ans += max(pqac.top().first, pqa.top().first);
	for(int i = 1; i <= N; i++){
		ans -= arr[i];
	}
	cout << ans;
}