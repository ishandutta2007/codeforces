#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int m,n,t_case;
char a[maxn],b[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%s%s",&n,&m,a+1,b+1);
		for(ri i=1;i<m;++i)
			if(a[n-i+1]!=b[m-i+1]){
				puts("NO");
				goto skip;
			}
		for(ri i=1;i<=n-m+1;++i)
			if(a[i]==b[1]){
				puts("YES");
				goto skip;
			}
		puts("NO");
		skip:;
	}
	return 0;
}