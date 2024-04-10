#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[100039],ans,t;
char s;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) {
			s=getchar();
			while(s<'0'||s>'9') s=getchar();
			a[i]=s-'0';
		}
		ans=0;
		for(i=2;i<=n;i++)if(a[i]==a[i-1]) ans++;
		printf("%d\n",(ans+1)/2);
	}
}