#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int a[N],b[N],d[N],l[N],t[N],m;
void add(int x){
	for(;x<=m;x+=x&-x)++t[x];
}
int sum(int x){
	int r=0;
	for(;x;x-=x&-x)r+=t[x];
	return r;
}
int main(){
	int n,i;
	long long z=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
	sort(b+1,b+n+1),m=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;++i)d[i]=lower_bound(b+1,b+m+1,a[i])-b;
	for(i=1;i<=n;++i)d[i]=m-d[i]+1;
	for(i=1;i<=n;++i){
		l[i]=sum(d[i]-1);
		add(d[i]);
	}
	memset(t,0,sizeof(t));
	for(i=n;i;--i){
		z+=(long long)sum(m-d[i]+1)*l[i];
		add(m-d[i]+2);
	}
	printf("%lld",z);
    return 0;
}