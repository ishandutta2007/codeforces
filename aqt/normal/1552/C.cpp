
// Problem : C. Maximize the Intersections
// Contest : Codeforces - Codeforces Global Round 15
// URL : https://codeforces.com/contest/1552/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, K;
pair<int, int> arr[105];
bool tkn[205];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> K;
		fill(tkn + 1, tkn + 1 + 2 * N, 0);
		for(int k = 1; k <= K; k++){
			cin >> arr[k].first >> arr[k].second;
			if(arr[k].second < arr[k].first){
				swap(arr[k].first, arr[k].second);
			}
			tkn[arr[k].first] = tkn[arr[k].second] = 1;
		}
		vector<int> vec;
		for(int i = 1; i <= 2 * N; i++){
			if(!tkn[i]){
				vec.emplace_back(i);
			}
		}
		int sz = vec.size();
		for(int i = 0; i < sz / 2; i++){
			arr[++K] = make_pair(vec[i], vec[i + sz / 2]);	
		}
		int ans = 0;
		/*
		for(int k = 1; k <= N; k++){
			int cnt = arr[k].second - arr[k].first - 1;
			int other = 2 * N - cnt - 2;
			for(int j = 1; j <= K; j++){
				bool good = 0;
				if(arr[k].first < arr[j].first && arr[j].first < arr[k].second && arr[j].second > arr[k].second){
					ans++;
					cnt--;
					other--;
					good = 1;
				}
				else if(arr[j].first < arr[k].first && arr[k].first < arr[j].second && arr[k].second > arr[j].second){
					cnt--;
					other--;
					good = 1;					
				}
				else if(arr[k].first < arr[j].first && arr[k].second > arr[j].second){
					cnt -= 2;
					good = 1;
				}
				else if(arr[j].first < arr[k].first && arr[j].second > arr[k].second){
					other -= 2;
				}
			}
			//cout << " " << other << " " << cnt << "\n";
			ans += min(other, cnt);
		}
		*/
		for(int k = 1; k <= N;k ++){
			for(int j = 1; j <= N; j++){
				if(arr[k].first < arr[j].first && arr[j].first < arr[k].second && arr[j].second > arr[k].second){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}