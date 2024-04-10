#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1005;

int n; 
char s[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%s",s);
    n=strlen(s);
    int c0=1,c1=1;
    for(int i=0;i<n;i++)
    	if(s[i]=='0')
		{
			printf("1 %d\n",c0);
			++c0;if(c0>4)c0-=4;
		}
		else
		{
			printf("4 %d\n",c1);
			c1+=2;if(c1>4)c1-=4;
		}
    return 0;
}