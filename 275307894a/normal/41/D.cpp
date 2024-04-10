#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
//#define max(a,b) ((a)>(b)?(a):(b))
//#define abs(x) ((x)>0?(x):-(x))
using namespace std;
int n,m,k,f[139][139][39],z[139][139][39],sx,sy,sans,now,tot,pus,anss,a[139][139],ans[139];
char _s;
int main(){
	memset(f,-0x3f,sizeof(f));
	register int i,j,h;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) cin>>_s,a[i][j]=_s-'0';
	}
	for(i=1;i<=m;i++) f[n][i][a[n][i]%(k+1)]=a[n][i];
	for(i=n-1;i>=1;i--){
		for(j=1;j<=m;j++){
			for(h=0;h<=k;h++){
				now=(k+1+(h-a[i][j])%(k+1))%(k+1);
				if(f[i+1][j-1][now]>f[i+1][j+1][now]){
					f[i][j][h]=f[i+1][j-1][now]+a[i][j];
					z[i][j][h]=1;
				}
				else{
					f[i][j][h]=f[i+1][j+1][now]+a[i][j];
					z[i][j][h]=-1;
				}
			}
		}
	}
	for(i=1;i<=m;i++)anss=max(f[1][i][0],anss);
	for(i=1;i<=m;i++){
		if(anss==f[1][i][0]){
		    printf("%d\n",anss);
		    sx=1;sy=i;sans=0;
		    while(sx!=n) ans[sx]=z[sx][sy][sans],now=sans,sans=(k+1+(sans-a[sx][sy])%(k+1))%(k+1),sy-=z[sx][sy][now],sx++;
		    printf("%d\n",sy);
		    for(i=n-1;i>=1;i--) printf("%c",ans[i]==-1?'L':'R');
		    return 0;
		}
	}
	printf("-1");
}