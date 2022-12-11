
// Problem : F. Binary String Reconstruction
// Contest : Codeforces - Codeforces Round #640 (Div. 4)
// URL : https://codeforces.com/contest/1352/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int cnt[3];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> cnt[0] >> cnt[1] >> cnt[2];
		int N = cnt[0] + cnt[1] + cnt[2] + 1;
		vector<int> v;
		if(cnt[0] && cnt[1] && cnt[2] && cnt[1]%2 == 0){
			v.push_back(1);
			cnt[1]--;
			cnt[0]++;
		}
		if(v.empty() && cnt[0]){
			v.push_back(0);
		}
		while(cnt[0]--){
			v.push_back(0);
		}
		if(cnt[1] && v.empty()){
			v.push_back(cnt[1]&1^1);
		}
		while(cnt[1]--){
			if(v.back()){
				v.push_back(0);
			}
			else{
				v.push_back(1);
			}
		}
		if(v.empty()){
			v.push_back(1);
		}
		while(cnt[2]--){
			v.push_back(1);
		}		
		for(int n : v){
			cout << n;
		}
		cout << "\n";
	}
}