#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
#define pb push_back
const int MAXN=100005;

int n,a[MAXN];
int ask(int x)
{
	int ans;
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&ans);
	return ans;
}
void reply(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}

inline bool same(int x,int y)
	{return (ll)x*y>=0;} 

int main()
{
    //XTQAKIOI
    scanf("%d",&n);
    n>>=1;
    if(n&1)reply(-1);
    int a=ask(1)-ask(n+1);
    if(!a)reply(1);
    int l=1,r=n,mid,b;
    while(l<=r)
    {
    	mid=(l+r+1)>>1;
    	b=ask(mid)-ask(mid+n);
    	if(!b)reply(mid);
    	if((ll)a*b>0){a=b;l=mid+1;}
    	else r=mid-1;
    }
    reply(-1);
    return 0;
}