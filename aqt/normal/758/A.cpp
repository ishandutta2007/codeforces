
// Problem : A. Holiday Of Equality
// Contest : Codeforces - Codeforces Round #392 (Div. 2)
// URL : https://codeforces.com/contest/758/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	int N;
	cin >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		v.push_back(n);
	}
	int m = *max_element(v.begin(), v.end());
	long long tot = 0;
	for(int n : v){
		tot += m - n;
	}
	cout << tot;
}