#include <bits/stdc++.h>
using namespace std;

int main(){
	int T=1; cin>>T;
	while(T--){
		string s,t; cin>>s>>t;
		int p=t.size()-1;
		for(int i=s.size()-1;i>=0;i--)~p&&s[i]==t[p]?p--:i--;
		puts(~p?"NO":"YES");
	}
	return 0;
}