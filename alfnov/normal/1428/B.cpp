#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		 int n;
		 cin>>n;
		 scanf("%s",s+1);
		 s[n+1]=s[1];
		 int ans=0;
		 for(int i=1;i<=n;i++)if(s[i]=='-'||s[i+1]=='-')ans++;
		 int flag=0;
		 for(int i=1;i<=n;i++)if(s[i]!='-')flag=s[i];
		 if(!flag)
		 {
		 	cout<<ans<<endl;
		 	continue;
		 }
		 for(int i=1;i<=n;i++)if(s[i]!=flag&&s[i]!='-')flag=0;
		 if(flag)ans=n;
		 cout<<ans<<endl;
	}
	return 0;
}