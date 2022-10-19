#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],bl,k,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		bl=unique(b+1,b+n+1)-b-1;
		ri ans=n;
		for(ri i=1;i<=n;++i){
			a[i]=lower_bound(b+1,b+bl+1,a[i])-b;
			if(i>1&&a[i]==a[i-1]+1)--ans;
		}
		puts(ans<=k?"Yes":"No");
	}
	return 0;
}