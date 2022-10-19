#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
set<int>ft;
char s[11];
inline bool ask(int x){
	ft.insert(x);
	if(x&1)printf("%d %d\n",x-1>>1,x+1>>1);
	else printf("%d %d\n",x>>1,x>>1);
	fflush(stdout);
	scanf("%s",s+1);
	return s[1]=='b';
}
int n;
int main(){
	scanf("%d",&n);
	bool f=ask(0);
	ri l=1,r=2e9-1;
	while(--n){
		ri mid=(ll)l+r>>1;
		if(ask(mid)^f)r=mid-1;
		else l=mid+1;
	}
	for(ri i=l;i<=r;++i)
		if(!ft.count(i)){
			ri x,y;
			if(i&1)x=i-1>>1,y=i+1>>1;
			else x=y=i>>1;
			if(x&&y<1e9)printf("%d %d %d %d",x,y,x-1,y+1);
			else printf("%d %d %d %d",x,y,x+1,y-1);
			break;
		}
	return 0;
}