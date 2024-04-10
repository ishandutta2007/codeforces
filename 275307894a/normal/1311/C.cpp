#include<cstdio>
#include<cstring>
using namespace std;
int n,m,q[200039][27],ans[139],x,y,t;
char s;
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		memset(ans,0,sizeof(ans));
		read(n);read(m);
		for(i=1;i<=n;i++) {
			s=getchar();
			while(s<'a'||s>'z') s=getchar();
			for(j=1;j<=26;j++) q[i][j]=q[i-1][j];
			q[i][s-96]++;
			//printf("%d\n",q[i][s-96]);
		}
		for(i=1;i<=m;i++){
			read(x);
			for(j=1;j<=26;j++) ans[j]+=q[x][j];
		}
		for(i=1;i<=26;i++) printf("%d ",ans[i]+q[n][i]);
		printf("\n");
	}
}