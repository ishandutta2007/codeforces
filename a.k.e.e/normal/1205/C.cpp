#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=55;

bool ask(int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}

int n,a[MAXN][MAXN];
void workxe(int x,int y)
{
	int tx=x,ty=y;
	for(;tx>1 && ty>1;--tx,--ty)
		if(a[tx-1][ty-1]<0)a[tx-1][ty-1]=a[tx][ty]^ask(tx-1,ty-1,tx,ty)^1;
	tx=x;ty=y;
	for(;tx<n && ty<n;++tx,++ty)
		if(a[tx+1][ty+1]<0)a[tx+1][ty+1]=a[tx][ty]^ask(tx,ty,tx+1,ty+1)^1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    memset(a,-1,sizeof(a));
    a[1][1]=1;a[n][n]=0;
    workxe(1,1);
    bool flag=0;
    for(int i=2;i<n;i++)
    	if(a[i][i]==a[i-1][i-1] && a[i][i]!=a[i+1][i+1])
    	{
    		int t=ask(i-1,i,i,i+1);
    		if(t)a[i-1][i]=a[i][i+1]=a[i-1][i-1]^ask(i-1,i-1,i,i+1)^1;
    		else {a[i-1][i]=a[i+1][i+1]^ask(i-1,i,i+1,i+1)^1;a[i][i+1]=a[i-1][i]^1;}
    		workxe(i-1,i);
    		flag=1;
    		break;
    	}
    if(!flag)
    {
	    for(int i=2;i<n;i++)
	    	if(a[i][i]!=a[i-1][i-1] && a[i][i]==a[i+1][i+1])
	    	{
	    		int t=ask(i-1,i,i,i+1);
	    		if(t)a[i-1][i]=a[i][i+1]=a[i+1][i+1]^ask(i-1,i,i+1,i+1)^1;
	    		else {a[i][i+1]=a[i-1][i-1]^ask(i-1,i-1,i,i+1)^1;a[i-1][i]=a[i][i+1]^1;}
	    		workxe(i-1,i);
	    		flag=1;
	    		break;
	    	}
	}
    for(int i=1;i<n;i++)
    {
    	for(int j=i+2;j<=n;j++)
    		a[i][j]=a[i][j-2]^ask(i,j-2,i,j)^1;
    	for(int j=i-1;j;j--)
    		a[i][j]=a[i][j+2]^ask(i,j,i,j+2)^1;
    }
    for(int i=1;i<n;i++)
    	a[n][i]=a[n-2][i]^ask(n-2,i,n,i)^1;
    printf("!\n");
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    		printf("%d",a[i][j]);
    	printf("\n");
    }
    fflush(stdout);
    return 0;
}