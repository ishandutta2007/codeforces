#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main(){
	cin >> n >> s;
	for(int i = 0; i + 1 < s.size(); ++i){
		if(s[i] != s[i + 1]){
			cout << "YES\n";
			cout << s[i] << s[i + 1];
			return 0;
		}
	}
	
	cout << "NO";
	return 0;
}