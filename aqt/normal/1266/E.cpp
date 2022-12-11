
// Problem : E. Spaceship Solitaire
// Contest : Codeforces - Codeforces Global Round 6
// URL : https://codeforces.com/contest/1266/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
map<pair<int, int>, int> mp;
int arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long tot = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		tot += arr[i];
	}
	cin >> Q;
	while(Q--){
		int a, b, c;
		cin >> a >> b >> c;
		if(mp.count(make_pair(a, b))){
			arr[mp[make_pair(a, b)]]++;
			if(arr[mp[make_pair(a, b)]] > 0){
				tot++;
			}
			mp.erase(make_pair(a, b));
		}
		mp[make_pair(a, b)] = c;
		arr[c]--;
		if(arr[c] >= 0){
			tot--;
		}		
		cout << tot << "\n";
	}
}