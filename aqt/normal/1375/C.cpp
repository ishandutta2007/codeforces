
// Problem : C. Element Extermination
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[300005], pre[300005], suf[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> v;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			while(v.size() > 1 && v.back() < arr[i]){
				v.pop_back();
			}
			if(v.size() == 1 && v.back() < arr[i]){
				
			}
			else{
				v.push_back(arr[i]);
			}
		}
		if(v.size() == 1){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
		/*
		suf[N+1] = 0;
		pre[0] = INT_MAX/2;
		for(int i = 1; i<=N; i++){
			pre[i] = min(pre[i-1], arr[i]);
		}
		for(int i = N; i; i--){
			suf[i] = max(suf[i+1], arr[i]);
		}
		bool good = 1;
		for(int i = 2; i<=N; i++){
			if(suf[i] < pre[i-1]){
				good = 0;
			}
		}
		cout << (good ? "YES\n" : "NO\n");
		*/
		
	}
}