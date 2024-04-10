#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
const int MAXN=300005,INF=1<<30,MAXK=20;

int n,a[MAXN],_log2[MAXN],rmq[MAXN<<1][MAXK],l[MAXN],r[MAXN];

void sparse()
{
    int t=0;
    for(int i=1;i<=n;i++)
    {
        if(i>=(1<<(t+1)))t++;
        _log2[i]=t;
        rmq[i][0]=a[i];
    }
    
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}

inline int RMQ(int l,int r)
{
    int t=_log2[r-l+1];
    return min(rmq[l][t],rmq[r-(1<<t)+1][t]);
}

int main()
{
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(!a[i])a[i]=INF;
    }
    sparse();
    for(int i=1;i<=n;i++)
    {
    	if(a[i]>=INF)continue;
    	if(!l[a[i]])l[a[i]]=i;
    	r[a[i]]=max(r[a[i]],i);
    }
    for(int i=1;i<=q;i++)
    {
    	if(!l[i])continue;
    	if(RMQ(l[i],r[i])<i)return 0*printf("NO\n");
    }
    if(!l[q])
    {
    	int flag=0;
    	for(int i=1;i<=n;i++)
    		if(a[i]>=INF)
    		{
    			flag=i;
    			break;
    		}
    	if(!flag)return 0*printf("NO\n");
    	a[flag]=q;
    }
    int t=0;
    for(int i=1;i<=n;i++)
    	if(a[i]<INF){t=i;break;}
    for(int i=t-1;i>0;i--)
		a[i]=a[t];
    for(int i=t+1;i<=n;i++)
    	if(a[i]>=INF)a[i]=a[i-1];
    printf("YES\n");
    for(int i=1;i<=n;i++)
    	printf("%d ",a[i]);
    printf("\n");
    return 0;
}