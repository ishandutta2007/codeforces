#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
using ll=long long;
ll a[N],b[N];
int c[N],p[N];
int main(){
	int n,i,j;
	bool fl=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&j),a[i]=a[i-1]+j;
	for(i=1;i<=n;++i)scanf("%d",&j),b[i]=b[i-1]+j;
	if(a[n]==b[n]){
		printf("%d\n",n);
		for(i=1;i<=n;++i)printf("%d ",i);
		printf("\n%d\n",n);
		for(i=1;i<=n;++i)printf("%d ",i);
		return 0;
	}
	if(a[n]>b[n])swap(a,b),fl=1;
	for(i=j=0;i<=n;c[i]=j-1,++i)while(a[i]>=b[j])++j;
	memset(p,-1,sizeof p);
	for(i=0;i<=n;++i){
		j=a[i]-b[c[i]];
		if(~p[j]){
			int la=p[j]+1,ra=i,lb=c[p[j]]+1,rb=c[i];
			if(fl)swap(la,lb),swap(ra,rb);
			printf("%d\n",ra-la+1);
			for(i=la;i<=ra;++i)printf("%d ",i);
			printf("\n%d\n",rb-lb+1);
			for(i=lb;i<=rb;++i)printf("%d ",i);
			return 0;
		}
		p[j]=i;
	}
	return 0;
}