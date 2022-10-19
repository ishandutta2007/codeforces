#include<bits/stdc++.h>
using namespace std;
char s1[1000005],s2[1000005];
int f1[30],f2[30];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		int n,k;
		cin>>n>>k;
		scanf("%s%s",s1+1,s2+1);
		for(int i=1;i<=n;i++)f1[s1[i]-'a'+1]++,f2[s2[i]-'a'+1]++;
		int flag=1;
		for(int i=1;i<=26;i++)
		{
			if(f1[i]<f2[i])
			{
				puts("No");
				flag=0;
				break;
			}
			if((f1[i]-f2[i])%k!=0)
			{
				puts("No");
				flag=0;
				break;
			}
			f1[i+1]+=f1[i]-f2[i];
		}
		if(flag)puts("Yes");
	}
	return 0;
}