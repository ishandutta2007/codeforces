#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	int res=0;
	for(int i=0;i<n;i+=2)
    {
        if(s[i]==s[i+1])
        {
            res++;
            s[i+1]='a'+'b'-s[i+1];
        }
    }
	printf("%d\n%s\n",res,s);
	return 0;
}