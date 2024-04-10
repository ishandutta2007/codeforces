#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	string s;
	string ans="0000000000";
	int n;
	cin>>n;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='L'){
			for(int i=0;i<10;i++)
			if(ans[i]=='0'){
				ans[i]='1';
				break;
			}
		}
		else if(s[i]=='R'){
			for(int i=9;i>=0;i--)
			if(ans[i]=='0'){
				ans[i]='1';
				break;
			}
		}
		else ans[s[i]-'0']='0';
	}
	cout<<ans<<endl;
	return 0;
}