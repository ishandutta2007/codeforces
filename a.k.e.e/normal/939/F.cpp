#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MAXK=105,INF=0x3f3f3f3f;

int n,m,l[MAXK],r[MAXK],f[MAXK][2][MAXN*2-1];
inline void chk(int &x,int y){if(x>y)x=y;}
int q[MAXN*2-1];

void work(int *a,int *b,int l,int r,int add)
{
	int front=1,rear=0;
	for(int i=l;i<=2*n;i++)
	{
		while(front<=rear && q[front]<i-r)++front;
		while(front<=rear && a[i-l]<=a[q[rear]])--rear;
		q[++rear]=i-l;
		chk(b[i],a[q[front]]+add);
	}
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    	scanf("%d%d",&l[i],&r[i]);
    memset(f,0x3f,sizeof(f));
    f[0][0][0]=0;
    for(int i=1;i<=m;i++)
    {
    	work(f[i-1][1],f[i][1],0,0,0);
    	work(f[i-1][1],f[i][0],0,r[i]-l[i],1);
    	work(f[i-1][1],f[i][1],0,r[i]-l[i],2);
    	work(f[i-1][0],f[i][0],r[i]-r[i-1],r[i]-r[i-1],0);
    	work(f[i-1][0],f[i][0],l[i]-r[i-1],r[i]-r[i-1],2);
    	work(f[i-1][0],f[i][1],l[i]-r[i-1],r[i]-r[i-1],1);
    }
    int t=f[m][1][n];
	if(r[m]>=n)chk(t,f[m][0][r[m]-n]);
    if(t>=INF)return 0*printf("Hungry\n");
    printf("Full\n%d\n",t);
    return 0;
}