#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=100005,X=1000000000;

int n,cor;
int ask(int x,int y)
{
	printf("%d %d\n",x,y);
	fflush(stdout);
	char op[7];
	scanf("%s",op);
	return op[0]=='w'?cor:1-cor;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    cor=ask(0,0);//same0 diff1
    int L=1,R=X*2,mid,x,y,ans=X*2,t;
    while(--n)
    {
    	mid=(1ll*L+R)>>1;
    	if(mid<=X)x=mid,y=0;
    	else x=X,y=mid-X;
    	t=ask(x,y);
    	if(t)R=mid-1,ans=mid;
    	else L=mid+1;
    }
    if(ans==1)printf("1 2 2 6\n");
    else if(ans<=X)printf("%d 2 %d 6\n",ans-1,ans-2);
    else if(ans<X*2)printf("%d %d %d %d\n",X-2,ans-X,X-6,ans-X+1);
    else printf("%d %d %d %d\n",X-2,X-1,X-6,X-2);
    return 0;
}