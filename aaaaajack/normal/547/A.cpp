#include<cstdio>
#include<algorithm>
#define N 1000100
using namespace std;
bool v1[N],v2[N];
int d1[N],d2[N];
int main(){
	int m,s1,t1,s2,t2,x1,y1,x2,y2,r1,r2,p;
	int f1,f2,n1,n2;
	long long i,lcm;
	scanf("%d",&m);
	scanf("%d%d",&s1,&t1);
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&s2,&t2);
	scanf("%d%d",&x2,&y2);
	for(i=s1,p=0;!v1[i];i=(i*x1+y1)%m,p++){
		d1[i]=p;
		v1[i]=true;
	}
	r1=i,n1=p-d1[i];
	for(i=s2,p=0;!v2[i];i=(i*x2+y2)%m,p++){
		d2[i]=p;
		v2[i]=true;
	}
	r2=i,n2=p-d2[i];
	if(!v1[t1]||!v2[t2]){
		printf("-1\n");
	}
	else{
		f1=d1[t1];
		f2=d2[t2];
		if(d1[r1]>d1[t1]){
			n1=0;
		}
		if(d2[r2]>d2[t2]){
			n2=0;
		}
		if(!n1&&!n2){
			if(d1[t1]==d2[t2]) printf("%d\n",d1[t1]);
			else printf("-1\n");
		}
		else if(!n1){
			if(d1[t1]>=d2[t2]&&(d1[t1]-d2[t2])%n2==0) printf("%d\n",d1[t1]);
			else printf("-1\n");
		}
		else if(!n2){
			if(d2[t2]>=d1[t1]&&(d2[t2]-d1[t1])%n1==0) printf("%d\n",d2[t2]);
			else printf("-1\n");
		}
		else{
			lcm=(max(f1,f2)/n1/n2+1LL)*n1*n2;
			for(i=f1;(i<f2||(i-f2)%n2)&&i<lcm;i+=n1);
			if(i<lcm) printf("%I64d\n",i);
			else printf("-1\n");
		}
	}
	return 0;
}