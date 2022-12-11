
// Problem : C. Bottom-Tier Reversals
// Contest : Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL : https://codeforces.com/contest/1558/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[2025];
vector<int> out;

void move(int p){
	reverse(arr+1, arr+1+p);
	out.emplace_back(p);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		bool good = 1;
		out.clear();
		for(int i = 1; i <= N; i++){
			cin >> arr[i];
			if(arr[i]%2 != i%2){
				good = 0;
			}
		}
		if(!good){
			cout << -1 << "\n";
			continue;
		}
		for(int i = N; i > 1; i-=2){
			int idx = find(arr+1, arr+1+N, i) - arr;
			move(idx);
			idx = find(arr+1, arr+1+N, i-1) - arr;
			move(idx-1);
			move(idx+1);
			move(3);
			move(i);
		}
		for(int i = 1; i <= N; i++){
			assert(arr[i] == i);
		}
		cout << out.size() << "\n";
		for(int n : out){
			cout << n << " ";
		}
		cout << "\n";
	}
}