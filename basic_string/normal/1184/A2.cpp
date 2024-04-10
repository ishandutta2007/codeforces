#include<bits/stdc++.h>
using namespace std;
namespace sub1{
void work(){
	long long r,x,w;
	scanf("%lld",&r),--r;
	for(x=1;x*x<=r;++x)if(r%x==0){
		w=r/x;
		if(w>=x+3&&((w&1)!=(x&1))){
			printf("%lld %lld\n",x,(w-x-1)/2);
			return;
		}
	}
	puts("NO");
}
}
namespace sub2{
const int N=2e5+3;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
char s[N];
bool a[N];
int ans[N],n;
int getans(int d){
	int i,j;
	bool s;
	for(i=1;i<=d;++i){
		for(s=0,j=i;j<=n;j+=d)s^=a[j];
		if(s)return 1;
	}
	return 0;
}
void work(){
	int i,d,w=0;
	scanf("%d%s",&n,s+1),memset(ans,-1,sizeof ans);
	for(i=1;i<=n;++i)if(s[i]=='1')a[i]=1;
	for(i=1;i<=n;++i){
		d=gcd(i,n);
		if(ans[d]==-1)ans[d]=getans(d);
		if(ans[d]==0)++w;
	}
	printf("%d",w);
}
}
namespace sub3{
const int N=1e5+3;
char a[N],b[N];
int to[199],n;
int get(char*s,int p,int r){
	int i,w=0;
	for(i=n;i;--i)w=(w*r+to[s[i]])%p;
	return w;
}
void work(){
	int m,i,j;
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	for(i='a';i<='z';++i)to[i]=i-'a'+1;
	for(i=m;;++i)for(j=2;j<30;++j)if(get(a,i,j)==get(b,i,j)){
		printf("%d %d\n",i,j);
		return;
	}
}
}
int main(){
	int opt;opt=2;
	//scanf("%d",&opt);
	if(opt==1)sub1::work();
	else if(opt==2)sub2::work();
	else sub3::work();
	return 0;
}