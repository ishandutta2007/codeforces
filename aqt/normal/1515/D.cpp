
// Problem : D. Phoenix and Socks
// Contest : Codeforces - Codeforces Global Round 14
// URL : https://codeforces.com/contest/1515/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N, L, R;
		cin >> N >> L >> R;
		vector<int> lft, rht;
		for(int i = 1; i <= L; i++){
			int n;
			cin >> n;
			lft.emplace_back(n);
		}
		for(int i = 1; i <= R; i++){
			int n;
			cin >> n;
			rht.emplace_back(n);
		}
		sort(lft.begin(), lft.end());
		sort(rht.begin(), rht.end());
		int idx1 = 0, idx2 = 0;
		int ans = 0;
		while(idx1 < lft.size() && idx2 < rht.size()){
			if(lft[idx1] == rht[idx2]){
				lft[idx1] = rht[idx2] = 0;
				idx1++;
				idx2++;
			}
			else if(lft[idx1] < rht[idx2]){
				idx1++;
			}
			else{
				idx2++;
			}
		}
		sort(lft.begin(), lft.end());
		sort(rht.begin(), rht.end());
		lft.erase(lft.begin(), upper_bound(lft.begin(), lft.end(), 0));
		rht.erase(rht.begin(), upper_bound(rht.begin(), rht.end(), 0));
		int szl = lft.size(), szr = rht.size();
		for(int i = 1; i < lft.size() && szl > szr; i++){
			if(lft[i] == lft[i-1]){
				lft[i] = lft[i-1] = 0;
				i++;
				ans++;
				szl -= 2;
			}
		}
		for(int i = 1; i < rht.size() && szl < szr; i++){
			if(rht[i] == rht[i-1]){
				rht[i] = rht[i-1] = 0;
				i++;
				ans++;
				szr -= 2;
			}
		}
		sort(lft.begin(), lft.end());
		sort(rht.begin(), rht.end());
		lft.erase(lft.begin(), upper_bound(lft.begin(), lft.end(), 0));
		rht.erase(rht.begin(), upper_bound(rht.begin(), rht.end(), 0));
		ans += (szl + szr)/2 + abs(szr-szl)/2;
		cout << ans << "\n";		
	}
}