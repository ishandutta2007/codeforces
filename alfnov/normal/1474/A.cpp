#include<bits/stdc++.h>
using namespace std;
char s[100005],t[100005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		scanf("%s",s+1);
		int lst=-1;
		t[0]=t[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(lst==2)t[i]='0';
				else t[i]='1';
				lst=t[i]-'0'+s[i]-'0';
			}else
			{
				if(lst==1)t[i]='0';
				else t[i]='1';
				lst=t[i]-'0'+s[i]-'0';
			}
		}
		cout<<t+1<<endl;
	}
	return 0;
}