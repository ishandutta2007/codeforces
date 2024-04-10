#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],cnt[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			++cnt[a[i]];
		}
		sort(a+1,a+n+1);
		for(ri i=1;i<=(m<<1);++i)cnt[i]+=cnt[i-1];
		for(ri i=1;i<=n;++i)
			if(a[i]!=a[i-1])
				for(ri j=a[i];j<=m;j+=a[i])
					if(cnt[j+a[i]-1]!=cnt[j-1]&&cnt[j/a[i]]==cnt[j/a[i]-1]){
						puts("No");
						goto skip;
					}
		puts("Yes");
		skip:;
		clear(cnt,m<<1);
	}
	return 0;
}