
// Problem : D. Cooperative Game
// Contest : Codeforces - Codeforces Round #545 (Div. 1)
// URL : https://codeforces.com/contest/1137/problem/D
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

bool chk1(){
	int n;
	cin >> n;
	bool ret = 1;
	while(n--){
		string s;
		cin >> s;
		if(s == "01"){
			ret = 0;
		}
	}
	return ret;
}

bool chk2(){
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		if(s == "0123456789"){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	do{
		cout << "next " << 0 << " " << 1 << endl;
		chk1();
		cout << "next " << 0 << endl;
	}
	while(chk1());
	do{
		cout << "next ";
		for(int i = 0; i<=9; i++){
			cout << i << " ";
		}
		cout << endl;
	}
	while(chk2());
	cout << "done" << endl;
}