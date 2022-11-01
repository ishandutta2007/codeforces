#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
	scanf("%d%d",&n,&k);
	char s[n+1];
	s[n]='\0';
	for(int i=0;i<n;i++) s[i]='0';
	int m=(n-k)/2;
	for(int i=m;i<n;i+=m+1) s[i]='1';
	printf("%s\n",s);
	return 0;
}