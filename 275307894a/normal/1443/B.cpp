#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,last,ans,t,tot,a,b;
char s;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);ans=0;last=0;
		for(i=1;;i++){
			s=getchar();
			if(s=='\n') break;
		}
		for(i=1;;i++){
			s=getchar();
			while(s!='0'&&s!='1'&&s!='\n') s=getchar();
			if(s=='\n') break;
			if(s=='1') {
				if(!tot) {
					if(last) ans+=min(a,(i-last-1)*b);
					tot=1;
				}
				else tot++;
			}
			else{
				if(tot) last=i-1;
				tot=0;
			}
		}
		if(last||tot) ans+=a;
		printf("%d\n",ans);
	}
}