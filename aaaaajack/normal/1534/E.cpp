#include<bits/stdc++.h>
#define N 2010
using namespace std;
int get_suf(int n,int k,int l){
	int red=(k*2-l)/2,act=k-red,x,y;
	printf("?");
	for(int i=1;i<=red;i++) printf(" %d",i);
	for(int i=n;i>n-act;i--) printf(" %d",i);
	puts("");
	printf("?");
	for(int i=1;i<=red;i++) printf(" %d",i);
	for(int i=n-act;i>n-act*2;i--) printf(" %d",i);
	puts("");
	fflush(stdout);
	scanf("%d%d",&x,&y);
	return x^y;
}
int get_pre(int n,int k,int l,int st){
	int red=(k*2-l)/2,act=k-red,x,y;
	int rs=(st+act*2-1)%n+1;
	printf("?");
	for(int i=st;i<st+act;i++) printf(" %d",i);
	for(int i=rs;i<rs+red;i++) printf(" %d",(i-1)%n+1);
	puts("");
	printf("?");
	for(int i=st+act;i<st+act*2;i++) printf(" %d",i);
	for(int i=rs;i<rs+red;i++) printf(" %d",(i-1)%n+1);
	puts("");
	fflush(stdout);
	scanf("%d%d",&x,&y);
	return x^y;
}
int get_con(int k, int st){
	printf("?");
	for(int i=st;i<st+k;i++) printf(" %d",i);
	puts("");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(n%2==1 && k%2==0) puts("-1");
	else if(n%k==0){
		int ans=0;
		for(int i=0;i<n/k;i++){
			ans^=get_con(k,k*i+1);
		}
		printf("! %d\n",ans);
	}
	else{
		int ans=0;
		int ex=n%k;
		if(n<k*2){
			if(ex%2==0){
				ans^=get_con(k,1);
				ans^=get_suf(n,k,ex);
			}
			else{
				ans^=get_suf(n,k,ex*2);
				int rem=n%(ex*2),blocks=n/(ex*2)-1;
				for(int i=0;i<blocks;i++) ans^=get_pre(n,k,ex*2,1+i*ex*2);
				if(rem) ans^=get_pre(n,k,rem,1+blocks*ex*2);
			}
		}
		else{
			if((ex+k)%2==0){
				ans^=get_suf(n,k,ex+k);
				n-=ex+k;
			}
			else{
				ans^=get_suf(n,k,ex);
				n-=ex;
			}
			for(int i=0;i<n/k;i++){
				ans^=get_con(k,k*i+1);
			}
		}
		printf("! %d\n",ans);
	}
	return 0;
}