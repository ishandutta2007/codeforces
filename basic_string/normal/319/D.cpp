#include<bits/stdc++.h>
using namespace std;
const int N=5e4+3;
char s[N];
using ul=unsigned long long;
ul p[N],h[N];
int n;
void in(){for(int i=1;i<=n;++i)h[i]=h[i-1]*131+s[i];}
ul get(int x,int l){return h[x+l]-h[x]*p[l];}
int lcp(int x,int y){
	int l=0,r=n-max(x,y)+1,m;
	while(l<=r){
		m=l+r>>1;
		if(get(x-1,m)==get(y-1,m))l=m+1;else r=m-1;
	}
	return r;
}
int lcs(int x,int y){
	int l=0,r=min(x,y),m;
	while(l<=r){
		m=l+r>>1;
		if(get(x-m,m)==get(y-m,m))l=m+1;else r=m-1;
	}
	return r;
}
bool chk(int l){
	for(int i=l*2;i<=n;i+=l)if(lcp(i-l,i)+lcs(i-l,i)>l)return 1;
	return 0;
}
void rb(int l){
	int m=l,i=l+1,k=0;
	for(;i<=n;s[++m]=s[i++])if(s[i]==s[i-l]){
		if(++k,k==l)k=0,m-=l;
	}else k=0;
	n=m;
}
int main(){
	int i;
	scanf("%s",s+1),n=strlen(s+1);
	for(in(),p[0]=i=1;i<=n;++i)p[i]=p[i-1]*131;
	for(i=1;i<=n;++i)if(chk(i))rb(i),in();
	s[n+1]=0,printf("%s",s+1);
	return 0;
}