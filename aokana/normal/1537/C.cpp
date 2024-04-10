#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		if(n==2){
			for(ri i=1;i<=n;++i)printf("%d ",a[i]);
			printf("\n");
			continue;
		}
		ri ans=a[2]-a[1],pos=1;
		for(ri i=2;i<n;++i)
			if(a[i+1]-a[i]<ans)
				ans=a[i+1]-a[i],pos=i;
		for(ri i=pos+1;i<=n;++i)printf("%d ",a[i]);
		for(ri i=1;i<=pos;++i)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}