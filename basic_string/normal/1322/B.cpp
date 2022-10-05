#include<bits/stdc++.h>
using namespace std;
const int N=17000000;
int n,a[400009],t1[N+9],t2[N+9];
void add(int*t,int x){
	for(;x<=N;x+=x&-x)++t[x];
}
int sum(int*t,int x){
	int r=0;
	for(;x;x-=x&-x)r+=t[x];
	return r;
}
int main(){
	int i,j,k,p,q,s=0;
	long long u;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1<<24;i;i>>=1){
		u=p=q=0,memset(t1,0,sizeof(t1)),memset(t2,0,sizeof(t2));
		for(j=1;j<=n;++j){
			k=a[j]&(i-1);
			if(a[j]&i){
				u+=p-sum(t1,i-k)+sum(t2,i-k);
				add(t1,k+1),++p;
			}else{
				u+=q-sum(t2,i-k)+sum(t1,i-k);
				add(t2,k+1),++q;
			}
		}
		if(u&(1ll))s|=i;
	}
	printf("%d",s);
	return 0;
}//