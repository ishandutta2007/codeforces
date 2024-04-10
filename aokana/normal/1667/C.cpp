#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int ans,n;
int main(){
	scanf("%d",&n);
	ans=(2*n-1+2)/3;
	printf("%d\n",ans);
	for(ri i=1,j=1;i<=ans;++i){
		printf("%d %d\n",i,j);
		j+=2;
		if(j>ans)j=2;
	}
	return 0;
}