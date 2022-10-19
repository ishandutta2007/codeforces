#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,s,tx,ty,a[1039][1039],b[1039][1039],z1[1039][1039],z2[1039][1039],ans[2039],tot,pus,head,sx,sy,now;
int main(){
	register int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&s);
			if(s==0)tx=i,ty=j;
			while(s%2==0&&s) a[i][j]++,s/=2;
			while(s%5==0&&s) b[i][j]++,s/=5;
		}
	}
	for(i=1;i<=n;i++) a[1][i]+=a[1][i-1],a[i][1]+=a[i-1][1],b[1][i]+=b[1][i-1],b[i][1]+=b[i-1][1],z1[1][i]=z2[1][i]=1;
	for(i=2;i<=n;i++){
		for(j=2;j<=n;j++){
			if(a[i-1][j]>a[i][j-1])z1[i][j]=1,a[i][j]+=a[i][j-1];
			else a[i][j]+=a[i-1][j];
			if(b[i-1][j]>b[i][j-1])z2[i][j]=1,b[i][j]+=b[i][j-1];
			else b[i][j]+=b[i-1][j];
		}
	}
	if(min(a[n][n],b[n][n])>1&&tx&&ty){
		printf("1\n");
		for(k=1;k<tx;k++) printf("D");
		for(k=1;k<ty;k++) printf("R");
		for(k=1;k<=n-tx;k++) printf("D");
		for(k=1;k<=n-ty;k++) printf("R");
		return 0;
	}
	if(a[n][n]<b[n][n]){
		printf("%d\n",a[n][n]);
		sx=sy=n;
		while(sx!=1||sy!=1) ans[++head]=z1[sx][sy],now=z1[sx][sy],sx-=now^1,sy-=now;
		for(i=head;i>=1;i--) printf("%c",ans[i]?'R':'D');
	}
	else{
		printf("%d\n",b[n][n]);
		sx=sy=n;
		while(sx!=1||sy!=1) ans[++head]=z2[sx][sy],now=z2[sx][sy],sx-=now^1,sy-=now;
		for(i=head;i>=1;i--) printf("%c",ans[i]?'R':'D');
	}
}