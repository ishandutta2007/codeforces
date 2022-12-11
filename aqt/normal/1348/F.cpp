
// Problem : F. Phoenix and Memory
// Contest : Codeforces - Codeforces Round #638 (Div. 2)
// URL : https://codeforces.com/contest/1348/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int l[200005], r[200005], p[200005];
pair<int, int> arr[200005];
int ans[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> l[i] >> r[i];
		arr[i] = make_pair(l[i], i);
	}
	sort(arr+1, arr+1+N);
	int idx = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 1; i <= N; i++){
		while(idx < N && arr[idx+1].first == i){
			pq.push(make_pair(r[arr[idx+1].second], arr[idx+1].second));
			idx++;
		}
		auto pr = pq.top();
		pq.pop();
		ans[i] = pr.second;
		p[pr.second] = i;
	}
	{
		vector<int> stk;
		for(int i = 1; i <= N; i++){
			while(stk.size() && r[stk.back()] < i){
				stk.pop_back();
			}
			if(stk.size() && l[ans[i]] <= p[stk.back()]){
				int a = ans[i];
				int b = stk.back();
				//cout << a << " " << b << endl;
				cout << "NO\n";
				for(int i = 1; i<=N; i++){
					cout << p[i] << " ";
				}
				cout << "\n";
				for(int i = 1; i <= N; i++){
					if(a == i){
						cout << p[b] << " ";
					}
					else if(b == i){
						cout << p[a] << " ";
					}
					else{
						cout << p[i] << " ";
					}
				}
				return 0;
			}
			stk.emplace_back(ans[i]);
		}
	}
	cout << "YES\n";
	for(int i = 1; i<=N; i++){
		cout << p[i] << " ";
	}
}