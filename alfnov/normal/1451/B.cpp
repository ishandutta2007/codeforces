#include<bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		scanf("%s",s+1);
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			int flag=0;
			for(int i=1;i<l;i++)if(s[i]==s[l])
			{
				puts("YES");
				flag=1;
				break;
			}
			for(int i=r+1;i<=n;i++)if(s[i]==s[r]&&!flag)
			{
				puts("YES");
				flag=1;
				break;
			}
			if(!flag)puts("NO");
		}
	}
	return 0;
}