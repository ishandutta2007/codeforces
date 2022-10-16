#include<bits/stdc++.h>
using namespace std;
int n;
char s[1002];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){if(s[i-1]!='1'&&s[i+1]!='1')cout<<"No",exit(0);}
		else{if(s[i-1]=='1'||s[i+1]=='1')cout<<"No",exit(0);}
	}
	cout<<"Yes";
	return 0;
}