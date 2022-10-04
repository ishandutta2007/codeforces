#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1000005;

int n,m;
inline int getx(int t){return (t-1)/m+1;}
inline int gety(int t){return (t-1)%m+1;}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i*2<=n*m+1;i++)
    {
    	printf("%d %d\n",getx(i),gety(i));
    	if(i*2==n*m+1)break;
    	printf("%d %d\n",getx(n*m+1-i),gety(n*m+1-i));
    }
    return 0;
}