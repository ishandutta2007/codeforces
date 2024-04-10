#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],b[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=m;++i)scanf("%d",a+i);
		sort(a+1,a+m+1);
		for(ri i=2;i<=m;++i)b[i-1]=a[i]-a[i-1]-1;
		b[m]=(a[1]+n-a[m]-1)%n;
		sort(b+1,b+m+1,greater<int>());
		ri ans=0,cnt=0;
		for(ri i=1;i<=m&&b[i]>cnt;++i){
			if(b[i]<=cnt+2)++ans,cnt+=2;
			else ans+=b[i]-cnt-1,cnt+=4;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}