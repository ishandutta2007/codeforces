#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t,ans,tot,pus,l[300039][2],r[300039][2],a[300039];
char s[300039],_s;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			_s=getchar();
			while(_s<'A'||_s>'R') _s=getchar();
			a[i]=_s=='L'?1:-1;
		}
		for(i=1;i<=n+1;i++) l[i][0]=r[i][0]=l[i][1]=r[i][1]=1;
		for(i=2;i<=n+1;i++){
			if(a[i-1]==1)l[i][0]=l[i-1][1]+1;
			else l[i][1]=l[i-1][0]+1;
		}
		for(i=n;i;i--){
			if(a[i]==-1) r[i][0]=r[i+1][1]+1;
			else r[i][1]=r[i+1][0]+1;
		}
		for(i=1;i<=n+1;i++) printf("%d ",l[i][0]+r[i][0]-1);
		printf("\n");
	}
}