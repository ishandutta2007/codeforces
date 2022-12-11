
// Problem : C. U2
// Contest : Codeforces - Codeforces Round #549 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1142/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<long long, long long> arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first >> arr[i].second;
		arr[i].second -= arr[i].first * arr[i].first;
	}
	sort(arr+1, arr+1+N);
	vector<pair<long long, long long>> stk;
	for(int i = 1; i<=N; i++){
		while(stk.size() >= 2){
			int idx = stk.size()-1;
			if((stk[idx].first-arr[i].first)*(stk[idx-1].second-arr[i].second)-(stk[idx].second-arr[i].second)*(stk[idx-1].first-arr[i].first)<=0){
				stk.pop_back();
			}
			else{
				break;
			}
		}
		stk.push_back(arr[i]);
	}
	int ans = 0;
	//cout << stk[0].first << " " << stk[0].second << "\n";
	for(int i = 1; i<stk.size(); i++){
		//cout << stk[i].first << " " << stk[i].second << "\n";
		if(stk[i].first != stk[i-1].first){
			ans++;
		}
	}
	cout << ans;
}