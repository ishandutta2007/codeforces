#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	int one=0,zero=0;
	for(int i=0;i<n;i++)
    {
        if(s[i]=='n') one++;
        if(s[i]=='z') zero++;
    }
    for(int i=0;i<one;i++) printf("1 ");
    for(int i=0;i<zero;i++) printf("0 ");
    printf("\n");
	return 0;
}