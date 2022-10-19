#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],cnt[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=n;++i)scanf("%d",b+i),cnt[i]=0;
		for(ri i=1,j=1;i<=n;++i){
			int tmp=b[i];
			if(j<=n&&a[j]==tmp){++j;continue;}
			if(cnt[tmp]&&a[j-1]==tmp){--cnt[tmp];continue;}
			while(j<=n&&a[j]!=tmp)++cnt[a[j++]];
			if(j>n){puts("NO");goto skip;}
			++j;
		}
		puts("YES");
		skip:;
	}
	return 0;
}