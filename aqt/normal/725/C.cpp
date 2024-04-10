
// Problem : C. Hidden Word
// Contest : Codeforces - Canada Cup 2016
// URL : https://codeforces.com/contest/725/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

string s;

bool chk(string c){
	int n = 0;
	while(c[n] != s[0]){
		n++;
	}
	for(int i = 1; i<27; i++){
		if(n != 0 && s[i] == c[n-1]){
			n = n-1;
		}
		else if(n != 25 && s[i] == c[n+1]){
			n = n+1;
		}
		else if(c[25-n] == s[i]){
			n = 25 - n;
		}
		else if(25-n-1 >= 0 && 25-n-1 != n && c[25-n-1] == s[i]){
			n = 25 - n - 1;
		}
		else if(25 - n + 1 <= 25 && 25 -n+1 != n && c[25-n+1] == s[i]){
			n = 25 - n + 1;
		}
		else{
			return 0;
		}
	}
	return 1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	string ans;
	for(int i = 0; i<27; i++){
		if(find(s.begin(), s.begin()+i, s[i]) == s.begin()+i){
			ans.push_back(s[i]);
		}
	}
	for(int i = 0; i<50; i++){
		ans = ans.back() + ans.substr(0, 25);
		//cout << ans << endl;
		if(chk(ans)){
			cout << ans.substr(0, 13) << "\n";
			ans = ans.substr(13, 13);
			reverse(ans.begin(), ans.end());
			cout << ans << "\n";
			return 0;
		}
	}
	cout << "Impossible";
}