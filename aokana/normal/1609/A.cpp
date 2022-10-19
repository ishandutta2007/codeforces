#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],n,t_case;
ll ans1,ans2,sum;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ans1=1,ans2=0,sum=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			while(a[i]%2==0)a[i]>>=1,ans1<<=1;
			ckmax(ans2,(ll)a[i]);
			sum+=a[i];
		}
		printf("%lld\n",(ans1-1)*ans2+sum);
	}
	return 0;
}