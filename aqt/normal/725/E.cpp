
// Problem : E. Too Much Money
// Contest : Codeforces - Canada Cup 2016
// URL : https://codeforces.com/contest/725/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
map<int, int> mp;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		mp[n]++;
	}
	int ans = T;
	int tot = 0;
	for(int n = T-1; n>1; n--){
		while(mp[n+1] && tot + n+1 <= T){
			tot += n+1;
			mp[n+1]--;
		}
		mp.erase(n+1);
		if(n + tot >= T){
			continue;
		}
		int temp = tot + n;
		int lst = T;
		//cout << "testing: " << n << "\n";
		while(temp < T){
			auto ptr = mp.upper_bound(min(lst-1, T-temp));
			if(ptr == mp.begin()){
				break;
			}
			ptr--;
			//cout << " " << (*ptr).first << "\n";
			lst = (*ptr).first;
			if(temp + 1LL*(*ptr).first * (*ptr).second <= T){
				temp += 1LL*(*ptr).first * (*ptr).second;
			}
			else{
				temp += (T-temp)/(*ptr).first * (*ptr).first;
			}
		}
		if(temp != T){
			ans = n;
		}
	}
	cout << (ans == T ? "Greed is good" : to_string(ans)) << "\n";
}