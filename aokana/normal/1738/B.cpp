#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
ll a[maxn],b[maxn];
int k,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		for(ri i=n-k+1;i<=n;++i)scanf("%lld",b+i),a[i]=b[i]-b[i-1];
		if(k==1){
			puts("YES");
			goto skip;
		}
		if(k==n){
			puts(is_sorted(a+1,a+n+1)?"YES":"NO");
			goto skip;
		}
		for(ri i=n-k+2;i<n;++i)
			if(a[i]>a[i+1]){
				puts("NO");
				goto skip;
			}
		if(b[n-k+1]>=0&&a[n-k+2]<0){
			puts("NO");
			goto skip;
		}
		if((n-k+1)*a[n-k+2]<b[n-k+1]){
			puts("NO");
			goto skip;
		}
		puts("YES");
		skip:;
	}
	return 0;
}