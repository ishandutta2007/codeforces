#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		bool f1=false,f2=false;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]==1)f1=true;
		}
		sort(a+1,a+n+1);
		for(ri i=1;i<n;++i)
			if(a[i+1]-a[i]==1)
				f2=true;
		puts(f1&&f2?"NO":"YES");
	}
	return 0;
}