#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string s;
	cin>>s; 
	int flag=0;
	if(s[0]=='?'||s[n-1]=='?')flag=1;
	for(int i=1;i<n;i++)
	{
		if(s[i]=='?'&&(s[i-1]==s[i+1]||s[i-1]=='?'))
		flag=1;
		else if(s[i]==s[i-1])
		{
			flag=0;
			break;
		}
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
	return 0;
 }