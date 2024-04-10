#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,a[1000039],nows[1000039],tots[1000039],f[1000039],l,r,mid,ls[1000039],rs[1000039];
long long ans;
inline void get(int x){while(x<=n) f[x]++,x+=x&-x;}
inline int find(int x){int ans=0;while(x) ans+=f[x],x-=x&-x;return ans;}
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),nows[i]=a[i];
	sort(nows+1,nows+n+1);
	for(i=1;i<=n;i++){
		tots[i]=tots[i-1];
		if(nows[i]!=nows[i-1]) tots[i]++;
	}
	for(i=1;i<=n;i++){
		l=0;r=n+1;
		while(l+1<r){
			mid=l+r>>1;
			if(nows[mid]<a[i]) l=mid;
			else r=mid;
		}
		a[i]=tots[r];
	}
	for(i=1;i<=n;i++){
		get(a[i]);
		ls[i]=find(n)-find(a[i]);
	}
	memset(f,0,sizeof(f));
	for(i=n;i;i--){
		get(a[i]);
		rs[i]=find(a[i]-1);
	}
	for(i=1;i<=n;i++) ans+=(long long)ls[i]*rs[i];
	printf("%lld\n",ans);
}///////////////////