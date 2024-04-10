#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=15,MAXM=4105,MAXK=105;

int n,m,w[MAXN],wu[MAXM];
char s[MAXN];
int v[MAXM];
struct Data
{
	int x,id;
	Data(int x=0,int id=0):x(x),id(id){}
	bool operator <(const Data &b)const
		{return x<b.x;}
}rk[MAXM];
int ans[MAXM][MAXK];

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int Q,k,x;
    cin>>n>>m>>Q;
    for(int i=n-1;i>=0;i--)
    	scanf("%d",&w[i]);
    for(int i=1;i<=m;i++)
    {
    	scanf("%s",s);
    	x=0;
    	for(int j=0;j<n;j++)
    		x=x*2+(s[j]-'0');
    	v[x]++;
    }
    for(int i=0;i<(1<<n);i++)
    {
    	for(int k=0;k<n;k++)
    		if(!(i&(1<<k)))
    			wu[i]+=w[k];
    	rk[i]=Data(wu[i],i);
    }
    sort(rk,rk+(1<<n));
    for(int i=0;i<(1<<n);i++)
    {
    	int sum=0,cur=0;
    	for(int j=0;j<=100;j++)
    	{
    		while(cur<(1<<n) && rk[cur].x==j)sum+=v[i^rk[cur++].id];
    		ans[i][j]=sum;
    	}
    }
    while(Q--)
    {
    	scanf("%s%d",s,&k);
    	x=0;
    	for(int j=0;j<n;j++)
    		x=x*2+(s[j]-'0');
    	printf("%d\n",ans[x][k]);
    }
    return 0;
}