#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,c[N][26];char s[N];
int main()
{
	scanf("%s",s+1);int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)c[i][j]=c[i-1][j];
		c[i][s[i]-'a']++;
	}
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		if(l==r){puts("Yes");continue;}
		int cc=0;
		for(int j=0;j<26;j++)if(c[r][j]-c[l-1][j])cc++;
		if(cc==1){puts("No");continue;}
		if(cc>=3){puts("Yes");continue;}
		if(s[l]==s[r])puts("No");else puts("Yes");
	}
	return 0;
}