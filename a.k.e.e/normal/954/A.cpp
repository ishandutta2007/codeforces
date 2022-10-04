#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=105;

int n;
char s[MAXN];

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%s",&n,s+1);
    int ans=n;
    for(int i=2;i<=n;i++)
    	if(s[i]!=s[i-1])
    	{
    		ans--;
    		s[i]=s[i+1];
    	}
    printf("%d\n",ans);
    return 0;
}