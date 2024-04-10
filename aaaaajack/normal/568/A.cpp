#include<cstdio>
#include<cstring>
#define N 2000000
using namespace std;
bool isp[N];
int prm[N],pcnt;
bool is_palin(int x){
	int a[10],sz=0;
	while(x) a[sz++]=x%10,x/=10;
	for(int i=0;i<sz;i++) if(a[i]!=a[sz-1-i]) return false;
	return true;
}
int main(){
	memset(isp,-1,sizeof(isp));
	isp[1]=false;
	for(int i=2;i<N;i++){
		if(isp[i]) prm[pcnt++]=i;
		for(int j=0;j<pcnt&&i*prm[j]<N;j++){
			isp[i*prm[j]]=false;
			if(i%prm[j]==0) break;
		}
	}
	int p,q,n=-1,c1=0,c2=0;
	scanf("%d%d",&p,&q);
	for(int i=1;i<N;i++){
		if(is_palin(i)) c2++;
		if(isp[i]) c1++;
		if(1LL*q*c1<=1LL*p*c2) n=i;
	}
	if(n==-1) puts("Palindromic tree is better than splay tree");
	else printf("%d\n",n);
	return 0;
}