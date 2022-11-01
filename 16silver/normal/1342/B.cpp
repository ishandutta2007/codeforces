#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		string s;
		cin >> s;
		int flag=1;
		for(int i=1;i<s.size();i++){
			if(s[i]!=s[i-1]) flag=0;
		}
		string tmp="";
		if(!flag){
			for(int i=0;i<s.size();i++){
				tmp+="01";
			}
		}
		else{
			tmp = s;
		}
		cout << tmp << "\n";
	}
}