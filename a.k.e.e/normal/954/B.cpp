#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=105,INF=1<<30;

int n;
char s[MAXN];

bool check(int l1,int l2,int k)
{
	for(int i=0;i<k;i++)
		if(s[l1+i]!=s[l2+i])
			return false;
	return true;
}

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%s",&n,s+1);
    for(int l=n/2;l>0;l--)
		if(check(1,1+l,l))
		{
			printf("%d\n",n-l+1);
			return 0;
		}
    printf("%d\n",n);
    return 0;
}