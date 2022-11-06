#include<bits/stdc++.h>
using namespace std;
int n;char c[200005];
int main()
{
	scanf("%d%s",&n,c+1);
	int s=0,t=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='(')s++;else s--;
		if(s<0)
		{
			if(!t)t=1,s++;
			else{puts("No");return 0;}
		}
	}
	if(t)s--;
	if(s)puts("No");else puts("Yes");
	return 0;
}