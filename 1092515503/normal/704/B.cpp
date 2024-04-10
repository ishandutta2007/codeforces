#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,nex[5010],s,t;
int X[5010],a[5010],b[5010],c[5010],d[5010];
ll res;
ll calc(int i,int j){
	if(i>j)return 0ll+X[i]-X[j]+c[i]+b[j];
	if(i<j)return 0ll+X[j]-X[i]+d[i]+a[j];
}
int main(){
	scanf("%d%d%d",&n,&s,&t),nex[s]=t;
	for(int i=1;i<=n;i++)scanf("%d",&X[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	res=calc(s,t);
	for(int i=1;i<=n;i++){
		if(i==s||i==t)continue;
		ll mnd=0x3f3f3f3f3f3f3f3f;int mnp;
		for(int j=s;j!=t;j=nex[j])if(calc(j,i)+calc(i,nex[j])-calc(j,nex[j])<mnd)
			mnd=calc(j,i)+calc(i,nex[j])-calc(j,nex[j]),mnp=j;
		res+=mnd;
		nex[i]=nex[mnp],nex[mnp]=i;
	}
	printf("%lld\n",res);
	return 0;
}