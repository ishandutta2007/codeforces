#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int x[N],y[N],d[N],v[N],o[3];
basic_string<int>p[N],q[N],g[N];
int main(){
	int n,m,i,j,k,l;
	unsigned long long a,b,c,s=0;
	scanf("%d%d%llu%llu%llu",&n,&m,&a,&b,&c),memset(v,9,N*4);
	for(i=1;i<=m;++i)if(scanf("%d%d",x+i,y+i),++d[x[i]],++d[y[i]],x[i]>y[i])swap(x[i],y[i]);
	for(i=0;i<n;++i)s+=(a*(n-i-1)*(n-i-2)/2+b*i*(n-i-1)+c*i*(i-1)/2)*i;
	for(i=1;i<=m;++i){
		if(q[j=x[i]]+=(k=y[i]),p[k]+=j,d[j]<d[k]||(d[j]==d[k]&&j<k))g[j]+=k;else g[k]+=j;
		s-=((2*(a*j+b*k)+c*(k+n))*(n-k-1)+(2*(a*j+c*k)+b*(j+k))*(k-j-1)+(2*(b*j+c*k)+a*(j-1))*j)/2;
	}
	for(i=0;i<n;++i){
		sort(p[i].begin(),p[i].end()),sort(q[i].begin(),q[i].end()),j=p[i].size(),k=q[i].size(),s+=(a*k*(k-1)/2+b*j*k+c*j*(j-1)/2)*i;
		for(l=0;l<j;++l)s+=(a*(k+j-l-1)+b*l)*p[i][l];
		for(l=0;l<k;++l)s+=(c*(j+l)+b*(k-l-1))*q[i][l];
	}
	for(i=0;i<n;++i){
		for(int j:g[i])v[j]=i;
		for(int j:g[i])for(int k:g[j])if(v[k]==i)o[0]=i,o[1]=j,o[2]=k,sort(o,o+3),s-=a*o[0]+b*o[1]+c*o[2];
	}
	printf("%llu",s);
	return 0;
}