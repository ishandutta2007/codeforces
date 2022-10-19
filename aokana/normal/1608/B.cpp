#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a,ans[maxn],b,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&a,&b);
		for(ri i=1;i<=n;++i)ans[i]=i;
		if(abs(a-b)>1||a+b>n-2){puts("-1");continue;}
		if(a==b){
			for(ri i=2;i<=n&&a;i+=2)--a,swap(ans[i],ans[i+1]);
		}
		else if(a==b+1){
			for(ri i=2;i<=n;i+=2)
				if(b)--b,ans[i]=i+1,ans[i+1]=i;
				else{
					for(ri j=i;j<=n;++j)ans[j]=n-(j-i);
					break;
				}
		}
		else if(b==a+1){
			swap(ans[1],ans[2]);
			for(ri i=3;i<=n&&a;i+=2)--a,swap(ans[i],ans[i+1]);
		}
		for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
		putchar(10);
	}
	return 0;
}