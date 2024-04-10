#include<cstdio>
#define N 11000000
using namespace std;
int t1,t2,t3,n1,n2,n3;
int f1[N]={},f2[N]={},f3[N]={};
int sum(int *a,int x){
	int r=0;
	while(x>0){
		r+=a[x];
		x-=x&-x;
	}
	return r;
}
void add(int *a,int x,int v){
	while(x<N){
		a[x]+=v;
		x+=x&-x;
	}
}
inline bool check(int t){
	return sum(f1,t)>=n1||sum(f2,t+t1)>=n2||sum(f3,t+t1+t2)>=n3;
}
int bs(int l,int r){
	if(r-l==1) return l;
	int m=(l+r)/2;
	if(check(m-1)) return bs(m,r);
	return bs(l,m);
}
int main(){
	int i,p,k,pre=1;
	scanf("%d%d%d%d%d%d%d",&k,&n1,&n2,&n3,&t1,&t2,&t3);
	for(i=0;i<k;i++){
		p=bs(pre,N);
		add(f1,p,1);
		add(f1,p+t1,-1);
		add(f2,p+t1,1);
		add(f2,p+t1+t2,-1);
		add(f3,p+t1+t2,1);
		add(f3,p+t1+t2+t3,-1);
		pre=p;
	}
	printf("%d\n",p+t1+t2+t3-1);
	return 0;
}