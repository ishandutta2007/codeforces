/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	string f = "heidi";
	cin >> str;
	int n = str.size();
	int ptr = 0;
	for(int i=0;i<n;i++){
		if(str[i] == f[ptr]) ++ptr;
		if(ptr == 5) break;
	}
	if(ptr == 5) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}