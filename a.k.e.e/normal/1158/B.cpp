#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,m;

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
	int k=(n-m)/2+1;
	for(int i=1;i<=n;i++)
	  	if(i%k)putchar('0');
	  	else putchar('1');
    return 0;
}