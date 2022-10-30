#include<cstdio>
#define N 100100
using namespace std;
int w[N];
int main(){
	int n,q,i,l,r,t,st=0,now;
	bool rev=false;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) w[i]=i;
	now=n;
	while(q--){
		scanf("%d%d",&t,&l);
		if(t==1){
			if(l>now-l){
				rev=!rev;
				l=now-l;
			}
			if(rev){
				for(i=now-l;i<now;i++){
					w[st+2*(now-l)-i]+=n-w[st+i];
				}
			}
			else{
				st+=l;
				for(i=0;i<l;i++){
					w[st+i]-=w[st-i];
				}
			}
			now-=l;
		}
		else{
			scanf("%d",&r);
			if(rev){
				int tmp=now-r;
				r=now-l;
				l=tmp;
			}
			printf("%d\n",w[st+r]-w[st+l]);
		}
	}
	return 0;
}