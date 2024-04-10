
// Problem : B. Food on the Plane
// Contest : Codeforces - Canada Cup 2016
// URL : https://codeforces.com/contest/725/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	long long row = 0;
	for(int i = 0; i<s.size()-1; i++){
		row *= 10;
		row += s[i] - '0';
	}
	row--;
	long long ans = 0;
	ans += row/4 * 16;
	if(row%4 == 0 || row%4 == 2){
		
	}
	else{
		ans += 7;
	}
	char c = s.back();
	if(c == 'f'){
		ans++;
	}
	if(c == 'e'){
		ans+=2;
	}
	if(c == 'd'){
		ans += 3;
	}
	if(c == 'a'){
		ans += 4;
	}
	if(c == 'b'){
		ans += 5;
	}
	if(c == 'c'){
		ans += 6;
	}
	cout << ans << "\n";
}