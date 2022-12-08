#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXLOGN 20
#define INF 1000000000
using namespace std;
int n,q,a[MAXN+1];
int sum(int x)
{
	int ret=0;
	for(;x;x-=x&-x)ret+=a[x];
	return ret;
}
void add(int x,int d)
{
	for(;x<=n;x+=x&-x)a[x]+=d;
}
int bisearch(int k){
    int x=0;
    for(int i=MAXLOGN;~i;--i){
    	int x1=x+(1<<i);
        if(x1<=n&&k>a[x1]){
            k-=a[x1];
            x=x1;
        }
    }
    return x+1;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        add(x,1);
    }
    for(int i=1;i<=q;i++)
    {
        int x;
        scanf("%d",&x);
        if(x>0)
        {
            add(x,1);
        }
        else
        {
            int v=bisearch(-x);
            add(v,-1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(sum(i))
        {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("0");
}