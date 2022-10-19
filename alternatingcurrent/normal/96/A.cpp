#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ){
		int pos = i;
		while(s[pos] == s[i] && pos < s.size()) pos++;
		if(pos - i >= 7){
			cout << "YES";
			return 0;
		}
		i = pos;
	}
	cout << "NO";
}