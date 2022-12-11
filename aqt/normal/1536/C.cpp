
// Problem : C. Diluc and Kaeya
// Contest : Codeforces - Codeforces Round #724 (Div. 2)
// URL : https://codeforces.com/contest/1536/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		string s;
		cin >> s;
		int preD = 0, preK = 0;
		map<pair<int, int>, int> mp;
		for(char c : s){
			if(c == 'D'){
				preD++;
			}
			else {
				preK++;
			}
			int G = __gcd(preD, preK);
			int a = preD / G;
			int b = preK / G;
			cout << ++mp[make_pair(a, b)] << " ";
		}
		cout << "\n";
	}
}