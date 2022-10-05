#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,P=1e9+7;
vector<int>w[N];
int a[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int main(){
	int n,i,j,k,l,u,v,s=0,t;
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d",a+i);
	sort(a,a+n);
	for(k=a[n-1],i=1;i<=k;++i)for(j=i;j<=k;j+=i)w[j].push_back(i);
	for(i=1;i<=k;++i){
		for(l=w[i].size(),u=0,j=t=1;j<l;++j)v=lower_bound(a,a+n,w[i][j])-a,t=t*1ll*qp(j,v-u)%P,u=v;
		s=(s+t*1ll*(qp(l,n-u)-qp(l-1,n-u)))%P;
	}
	printf("%d",(s+P)%P);
	return 0;
}