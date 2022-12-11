
// Problem : B. Take Your Places!
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> odd;
		for(int i = 1; i <= N; i++){
			int n;
			cin >> n;
			if(n%2 == 1){
				odd.push_back(i);
			}
		}
		long long opt1 = 0, opt2 = 0;
		if(odd.size() == N / 2){
			for(int i = 2; i <= N; i += 2){
				opt1 += abs(odd[i/2-1] - i);
			}
		}
		else{
			opt1 = LLONG_MAX;
		}
		if(odd.size() == N - N / 2){
			for(int i = 1; i <= N; i += 2){
				opt2 += abs(odd[i/2] - i);
			}
		}
		else{
			opt2 = LLONG_MAX;
		}
		long long ans = min(opt1, opt2);
		if(ans == LLONG_MAX){
			ans = -1;
		}
		cout << ans << "\n";
	}
}