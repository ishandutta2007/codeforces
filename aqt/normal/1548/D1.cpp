
// Problem : D1. Gregor and the Odd Cows (Easy)
// Contest : Codeforces - Codeforces Round #736 (Div. 1)
// URL : https://codeforces.com/contest/1548/problem/D1
// Memory Limit : 256 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long N;
pair<long long, long long> arr[6005];
long long cnt[20][20];

bool good(int x1, int y1, int x2, int y2, int x3, int y3){

	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i].first >> arr[i].second;
		cnt[arr[i].first%4][arr[i].second%4]++;
	}
	vector<pair<long long, long long>> vec;
	for(int i = 0; i < 16; i+=2){
		for(int j = 0; j < 16; j+=2){
			vec.emplace_back(i, j);
		}
	}
	long long ans = N * (N - 1) * (N - 2) / 6;
	/*
	for(int i = 0; i < vec.size(); i++){
		for(int j = i; j < vec.size(); j++){
			for(int k = j; k < vec.size(); k++){
				
			}
		}
	}
	*/
	ans -= cnt[0][0] * cnt[0][2] * cnt[2][0];
	ans -= cnt[0][0] * cnt[0][2] * cnt[2][2];
	ans -= cnt[0][0] * cnt[2][0] * cnt[2][2];
	ans -= cnt[0][2] * cnt[2][0] * cnt[2][2];
	cout << ans << "\n";
}