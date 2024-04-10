#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1005;

int k;
char s[15][15];
void move(int x,int y,int z)
{
	printf("next");
	if(x)printf(" 0");
	if(y)printf(" 1 2 3 4 5 6 7 8");
	if(z)printf(" 9");
	printf("\n");
	fflush(stdout);
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%s",s[i]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int i;
    for(i=1;;i++)
    {
		move(1,1,0);
	    move(1,0,0);
	    if(k==2)break;
	}
	while(1)
	{
		move(1,1,1);
		if(k==1)break;
	}
	printf("done\n");
	fflush(stdout);
    return 0;
}