#include<bits/stdc++.h>
using namespace std;
char S[202020],T[202020];
int main()
{
	int lens,lent;
	scanf("%d%d",&lens,&lent);
	scanf("%s%s",S+1,T+1);
	
	int pos=0;
	for(int i=1;i<=lens;i++)
	if(S[i]=='*')
		pos=i;
	
	if(pos==0)
	{
		if(lens!=lent)
		{
			puts("NO");
			return 0;
		}
		for(int i=1;i<=lens;i++)
		if(S[i]!=T[i])
		{
			puts("NO");
			return 0;
		}
		puts("YES");
		return 0;
	}
	
	if(lens>lent+1)
	{
		puts("NO");
		return 0;
	}
	
	
	for(int i=1;i<pos;i++)
	{
		if(i>lent)
		{
			puts("NO");
			return 0;
		}
		if(S[i]!=T[i])
		{
			puts("NO");
			return 0;
		}
	}
	for(int i=1;lens-i+1>pos;i++)
	if(S[lens-i+1]=='*')
		break;
	else
	{
		if(i>lent)
		{
			puts("NO");
			return 0;
		}
		if(S[lens-i+1]!=T[lent-i+1])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}