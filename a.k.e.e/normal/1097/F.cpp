#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

int n,a[7005],prm[7005],mu[7005],am,pn;
bool notp[7005];
bitset<7005> b[MAXN],bas[7005];
void table()
{
	memset(notp,0,sizeof(notp));
	notp[0]=notp[1]=1;
	a[1]=am=mu[1]=1;
	for(int i=2;i<=7000;i++)
	{
		if(!notp[i]){prm[++pn]=i;mu[i]=1;}
		for(int j=1;j<=pn && i*prm[j]<=7000;j++)
		{
			notp[prm[j]*i]=1;
			if(i%prm[j])
				mu[i*prm[j]]=mu[i];
			else
			{
				mu[i*prm[j]]=0; 
				break;
			}
		}
		if(mu[i]==1)a[++am]=i;
	}
}

int main()
{
    int Q,op,x,y,z;
    scanf("%d%d",&n,&Q);
    table();
    for(int i=1;i<=7000;i++)
    	for(int j=1;j<=am && i*a[j]<=7000;j++)
    		bas[i][i*a[j]]=1;
    for(int kase=1;kase<=Q;++kase)
    {
    	scanf("%d%d%d",&op,&x,&y);
    	if(op==1)
    	{
    		b[x]=0;
    		for(int i=1;i*i<=y;i++)
    			if(!(y%i))b[x][i]=b[x][y/i]=1;
    	}
    	else if(op==2)
    	{
    		scanf("%d",&z);
    		b[x]=b[y]^b[z];
    	}
    	else if(op==3)
    	{
    		scanf("%d",&z);
    		b[x]=b[y]&b[z];
    	}
    	else
    	{
    		int ans=(b[x]&bas[y]).count();
    		putchar((ans&1)+'0');
    	}
    	/*printf("Case #%d:\n",kase);
    	for(int i=1;i<=n;i++)
    	{
    		putchar('\t');
			for(int j=1;j<=6;j++)
				putchar(b[i][j]+'0');
			putchar('\n');
		}*/
    }
    return 0;
}