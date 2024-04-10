#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int a[N],sx[N*2],sy[N*2],u[N],v[N],w[N],o[N];
int main(){
	int n,i,j=0,k,l,tp=0,tw=0,to=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=n;i;--i){
		if(a[i]==0)continue;
		if(a[i]==1){
			sx[++tp]=++j,sy[tp]=i,u[i]=j,w[++tw]=i;
			if(j>n)return puts("-1"),0;
		}else if(a[i]==2){
			if(tw){
				sx[++tp]=u[w[tw]],sy[tp]=i,u[i]=u[w[tw]];
				o[++to]=w[tw],o[++to]=i,--tw;
			}else return puts("-1"),0;
			
		}else{
			sx[++tp]=++j,sy[tp]=i,u[i]=j;
			if(j>n)return puts("-1"),0;
			if(to){
				sx[++tp]=j,sy[tp]=o[to],--to;
			}else if(tw){
				sx[++tp]=j,sy[tp]=w[tw],--tw;
			}else return puts("-1"),0;
			o[++to]=i;
		}
	}
	printf("%d\n",tp);
	for(i=1;i<=tp;++i)printf("%d %d\n",n-sx[i]+1,sy[i]);
	return 0;
}