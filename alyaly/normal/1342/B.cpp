#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,a,b;
string s;
signed main(){
	cin>>T;
	while(T--){
		cin>>s;
		bool nfl=1;
		for(int i=1;i<s.size();i++) if(s[i]!=s[i-1]) nfl=0;
		if(nfl){
			cout<<s<<endl;
		}else{
			for(int i=0;i<s.size();i++){
			if(s[i]=='0') printf("10");
			else printf("10");
		}
		printf("\n");
		}
		
	}
	return 0;
}
/*

*/