#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],f[2][maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri l=1919810,r=-1919810;
		for(ri i=2;i<=n;++i)
			if(a[i]==a[i-1]){
				l=i;
				break;
			}
		for(ri i=n-1;i;--i)
			if(a[i]==a[i+1]){
				r=i;
				break;
			}
		if(l==r)puts("1");
		else printf("%d\n",max(r-l,0));
		skip:;
	}
	return 0;
}