#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

typedef long long ll;
using namespace std;

int lp[10]={1,0,0,0,1,0,1,0,2,1};
int k;

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>k;
    if(k>36)
    {
    	printf("-1\n");
    	return 0;
    }
    while(k>=2)
    {
    	k-=2;
    	putchar('8');
    }
    if(k)putchar('6');
    putchar('\n');
    return 0;
}