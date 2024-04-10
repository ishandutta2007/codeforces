#include<bits/stdc++.h>
using namespace std;
char s[1010];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
	if(s[i]=='8')
		cnt++;
	printf("%d\n",min(cnt,n/11));
	return 0;
}