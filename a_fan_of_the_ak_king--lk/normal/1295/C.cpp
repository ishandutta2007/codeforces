#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int t,Next[100005][26],i;
char a[100005],b[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);
		int len=strlen(a);
		for(i=0;i<26;++i)
			Next[len][i]=len;
		for(i=len-1;i>=0;--i)
		{
			for(int j=0;j<26;++j)
				Next[i][j]=Next[i+1][j];
			Next[i][a[i]-'a']=i;
		}
		int ans=1,s=0;
		for(i=0;b[i];++i)
		{
			s=Next[s][b[i]-'a'];
			if(s>=len)
			{
				s=Next[0][b[i]-'a'];
				if(s>=len)
				{
					ans=-1;
					break;
				}
				++ans;
			}
			++s;
		}
		cout<<ans<<endl;
	}
}