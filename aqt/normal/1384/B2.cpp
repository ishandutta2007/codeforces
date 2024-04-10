
// Problem : B2. Koa and the Beach (Hard Version)
// Contest : Codeforces - Codeforces Round #659 (Div. 2)
// URL : https://codeforces.com/contest/1384/problem/B2
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[300005];
int lft[300005], rht[300005];
bool good[300005];

bool inter(int l, int r, int k){
	return (l <= k && r >= k);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K, L;
		cin >> N >> K >> L;
		bool bad = 0;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			good[i] = 0;
			if(arr[i] > L){
				bad = 1;
			}
			else if(arr[i]+K > L){
				lft[i] = K-(L - arr[i]);
				rht[i] = 2*K-(K-(L-arr[i]));
			}
			else{
				good[i] = 1;
				lft[i] = 2*K;
				rht[i] = 0;
			}
			//cout << lft[i] << " " << rht[i] << "\n";
		}
		if(bad){
			cout << "No\n";
			continue;
		}
		for(int i = 1; i<=N; i++){
			lft[i] -= i;
			rht[i] -= i;
			//cout << lft[i] << " " << rht[i] << "\n";
			//lft[i] %= 2*K;
			//rht[i] %= 2*K;
			//lft[i] += 2*K;
			//rht[i] += 2*K;
			//lft[i] %= 2*K;
			//rht[i] %= 2*K;
			
		}
		good[0] = 1;
		/*
		for(int i = 1; i<=N; i++){
			if(good[i] || good[i-1] || 
			inter(rht[i], lft[i]+2*K, rht[i-1]) || inter(rht[i]-2*K, lft[i], lft[i-1]) ||
			inter(rht[i-1], lft[i-1]+2*K, rht[i]) || inter(rht[i-1]-2*K, lft[i-1], lft[i])){
				
			}
			else{
				bad = 1;
			}
		}
		*/
		int curl = INT_MIN, curr = INT_MAX;
		for(int i = 1; i<=N; i++){
			if(good[i]){
				curl = INT_MIN;
				curr = INT_MAX;
			}
			else{
				curl = max(curl, lft[i]);
				curr = min(curr, rht[i]);
			}
			if(curl > curr){
				bad = 1;
			}
			//cout << good[i] << "\n";
			//cout << curl << " " << curr << "\n";
			//cout << " " << i << " " << lft[i] << " " << rht[i] << "\n";
		}
		if(bad){
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
		}
	}
}