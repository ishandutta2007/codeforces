#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int a,b,c,d,e,f,ans,tot,pus;
int main(){
	register int i;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	if(e<f){
		tot=min(min(c,d),b);
		ans+=f*tot;
		c-=tot;
		b-=tot;
		d-=tot;
		ans+=min(a,d)*e;
	}
	else{
		tot=min(a,d);
		ans+=e*tot;
		a-=tot;
		d-=tot;
		ans+=f*min(min(c,d),b);
	}
	printf("%d",ans);
	return 0;
}