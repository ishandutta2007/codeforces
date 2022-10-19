#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),ans=0;
		s[0]=22;
		for(int i=2;i<=n;i++)
		{
			if(s[i]!=35&&(s[i]==s[i-2]||s[i]==s[i-1]))
			{
				s[i]=35;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}