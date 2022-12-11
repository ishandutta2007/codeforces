
// Problem : C. Lock Puzzle
// Contest : Codeforces - Codeforces Round #467 (Div. 1)
// URL : https://codeforces.com/problemset/problem/936/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
string s, t;
vector<int> ans;

void f(int i){
	//cout << i << endl;
	string pre = s.substr(0, i+1), suf = s.substr(i+1);
	reverse(suf.begin(), suf.end());
	s = suf + pre;
	ans.push_back(N-i-1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s >> t;
	string a = s, b = t;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(a != b){
		cout << -1 << "\n";
		return 0;
	}
	int idx = (N-1)/2;
	for(int i = 0; i<N; i++){
		if(i%2 == 0){
			idx -= i;
		}
		else{
			idx += i;
		}
		//cout << idx << endl;
		int nxt = find(s.begin(), s.end()-i-1, t[idx]) - s.begin();
		//cout << "nxt: " << nxt << endl;
		f(nxt);
		f(N-2);
		f(i);
		//cout << s << endl;
	}
	if(N%2 == 0){
		f(-1);
	}
	cout << ans.size() << "\n";
	for(int n : ans){
		cout << n << " ";
	}
}