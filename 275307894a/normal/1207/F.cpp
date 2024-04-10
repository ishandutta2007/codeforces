#include<cstdio>
#include<cmath>
using namespace std;
int n=500000,m,k,x,y,z,a[500039],fs[1539][1539],ans;
inline void read(int &x){
	char s=getchar();x=0;int f=1;
	while(s<'0'||s>'9') f=(s=='-'?-1:1),s=getchar();
	while(s>='0'&&s<='9') x=x*10+s-48,s=getchar();x*=f;
}
int main(){
	//freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&m);
	k=sqrt(50000);
	while(m--){
		read(x);read(y);read(z);
		if(x==1){
			a[y]+=z;
			for(i=1;i<=k;i++) fs[i][y%i]+=z;
		}
		else{
			ans=0;
			if(y<=k)ans=fs[y][z];
			else for(i=z;i<=n;i+=y) ans+=a[i];
			printf("%d\n",ans);
		}
	}
}