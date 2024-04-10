#include<bits/stdc++.h>
using namespace std;
char S[202020];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",S+1);
	int tmp=0;
	for(int i=1;i<=n;i++)
	if(S[i]=='(')
	{
		if(k>0)
		{
			k-=2;
			tmp++;
			printf("(");
		}
	}
	else if(S[i]==')')
	{
		if(tmp>0)
		{
			tmp--;
			printf(")");
		}
	}
	return 0;
}