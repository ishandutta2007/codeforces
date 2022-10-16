// NAIVE
#include<cstdio>
#include<cstring>
int n,a[53][53][53],b[53][53][53];
void draw(int o,int x,int y,int z,int dx,int dy,int dz,int n,int m,int id,int did)
{
    for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
	    a[x][y][z]=id,id+=did;
	    if(j<m) x+=dx,y+=dy,z+=dz;
	    else if(o==1||o==-1) x+=o,dy*=-1,dz*=-1;
	    else if(o==2||o==-2) y+=o/2,dx*=-1,dz*=-1;
	    else z+=o/3,dx*=-1,dy*=-1;
	}
} 
void add(int n)
{
    int m=n*n*n;
    draw(1,1,0,1,0,0,1,n,n,0,-1);
    if(n&1)
    {
	draw(-2,0,n,1,0,0,1,n+1,n,m+1,1),draw(1,0,0,0,0,1,0,n+1,n+1,m+n*(n+1)+1,1);
	for(int i=1;i<=n+1;++i) for(int j=1;j<=n+1;++j) for(int k=1;k<=n+1;++k) b[i][j][k]=a[n-i+1][k-1][n-j+1]+n*n;
    }
    else 
    {
	draw(3,0,n,1,0,-1,0,n,n+1,m+1,1),draw(1,0,n,n+1,0,-1,0,n+1,n+1,m+n*(n+1)+1,1);
	for(int i=1;i<=n+1;++i) for(int j=1;j<=n+1;++j) for(int k=1;k<=n+1;++k) b[i][j][k]=a[n-i+1][k-1][j]+n*n;
    }
    memcpy(a,b,sizeof b);
}
int main()
{
    scanf("%d",&n),a[1][1][1]=1;
    for(int i=1;i<n;++i) add(i);
    for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=n;++j) for(int k=1;k<=n;++k) printf("%d%c",a[i][j][k],k==n?'\n':' ');
}