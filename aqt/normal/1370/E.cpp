
// Problem : E. Binary Subsequence Rotation
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1370/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
string s, t;
string srts, srtt;
set<int> a, b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> s >> t;
	srts = s, srtt = t;
	sort(srts.begin(), srts.end());
	sort(srtt.begin(), srtt.end());
	if(srts != srtt){
		cout << -1 << "\n";
		return 0;
	}
	for(int i =1; i<=N; i++){
		if(s[i-1] == '0' && t[i-1] == '1'){
			a.insert(i);
		}
		else if(s[i-1] == '1' && t[i-1] == '0'){
			b.insert(i);
		}
	}
	int ans = 0;
	while(a.size() && b.size()){
		ans++;
		if(*a.begin() > *b.begin()){
			swap(a, b);
		}
		int lst = 0;
		do{
			lst = *a.lower_bound(lst);			
			a.erase(lst);
			swap(a, b);
		}
		while(a.lower_bound(lst) != a.end());
	}
	cout << ans + a.size() + b.size() << "\n";
}