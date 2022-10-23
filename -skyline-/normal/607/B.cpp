#include <bits/stdc++.h>
using namespace std;
int n,a[505],f[505][505];
int cty(int x,int y){
    if(f[x][y]) return f[x][y];
    if(a[x]==a[y]) f[x][y]=cty(x+1,y-1);
    else f[x][y]=n;
    for(int i=x;i<y;i++)f[x][y]=min(f[x][y],cty(x,i)+cty(i+1,y));
    return f[x][y];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),f[i][i]=1,f[i-1][i]=a[i]==a[i-1]?1:2;
    printf("%d\n",cty(1,n));
	return 0;
}