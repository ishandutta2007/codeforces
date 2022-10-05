#include<bits/stdc++.h>
using namespace std;
basic_string<int>a,b,c,d;
char st[9];
int qry(){
	printf("? %u %u\n",a.size(),b.size());
	for(int i:a)printf("%d ",i);puts("");
	for(int i:b)printf("%d ",i);puts("");
	fflush(stdout),scanf("%s",st);
	if(st[0]=='F')return 1;
	if(st[0]=='S')return -1;
	return 0;
}
int main(){
	int T,n,i,j,u,l,r,m;
	for(srand(1437),scanf("%d",&T);T--;){
		scanf("%d%*d",&n),u=1;
		for(i=0;i<25;++i){
			j=rand()%n+1,a=u,b=j;
			if(u!=j&&qry()<0)u=j;
		}
		for(j=1,a=u;;){
			for(b={},i=a.size();j=j==u?j+1:j,i&&j<=n;--i,++j)b+=j;
			while(a.size()>b.size())a.pop_back();
			if(qry()){
				l=1,r=b.size(),c=a,d=b;
				while(l<=r){
					m=l+r>>1,a=c.substr(0,m),b=d.substr(0,m);
					if(qry())r=m-1;else l=m+1;
				}
				printf("! %d\n",d[r]),fflush(stdout);
				break;
			}
			a+=b;
		}
	}
	return 0;
}