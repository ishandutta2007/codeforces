#include<cstdio>
#include<cstring>
#define N 200100
using namespace std;
int fa[N],fb[N];
int a[N],b[N],c[N],s[N];
int sum(int *f,int x){
	x++;
	int r=0;
	while(x){
		r+=f[x];
		x-=x&-x;
	}
	return r;
}
void fix(int *f,int x,int v){
	x++;
	while(x<N){
		f[x]+=v;
		x+=x&-x;
	}
}
int find(int *f,int x){
	int r=0,s=(1<<17),acc=0;
	while(s){
		if(r+s<N&&acc+f[r+s]<x){
			acc+=f[r+s];
			r+=s;
		}
		s>>=1;
	}
	return r;
}
			
int main(){
	int n,i,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(i=n-1;i>=0;i--){
		s[i]=sum(fa,a[i])+sum(fb,b[i])+c[i];
		fix(fa,a[i],1);
		fix(fb,b[i],1);
		if(s[i]>=n-i){
			if(i) c[i-1]=s[i]/(n-i);
			s[i]%=(n-i);
		}
	}
	for(i=0;i<n;i++){
		if(i) putchar(' ');
		printf("%d",tmp=find(fa,s[i]+1));
		fix(fa,tmp,-1);
	}
	putchar('\n');
	return 0;
}