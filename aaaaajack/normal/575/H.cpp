#define Q 1000000007
#include<cstdio>
int inv(int a){
	int x=a,r=1,y=Q-2;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
int main(){
	int hf=inv(2),ans,n,add,ter;
	scanf("%d",&n);
	ans=1;
	for(int i=0;i<n;i++) ans=(ans+ans+1)%Q;
	add=(ans+Q-1)%Q;
	ter=1;
	for(int i=1;i<=n;i++){
		ter=1LL*ter*(n+i)%Q*inv(i)%Q;
		ans=(ans+add)%Q;
		add=(add+Q-ter)%Q;
		add=(add+add)%Q;
	}
	printf("%d\n",ans);
	return 0;
}