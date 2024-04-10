#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		scanf("%s",s+1);
		int n=strlen(s+1);
		int u=0,d=0,l=0,r=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='U')u++;
			if(s[i]=='D')d++;
			if(s[i]=='L')l++;
			if(s[i]=='R')r++;
		}
		if(y<-d||y>u||x<-l||x>r)puts("NO");
		else puts("YES");
	}
	return 0;
}