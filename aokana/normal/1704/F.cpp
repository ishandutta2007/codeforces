#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=5e5+10;
int sg[maxn];
int init=[](int *sg){
	sg[2]=1;
	for(ri i=3;i<1000;++i){
		bitset<100>b;
		b.flip();
		for(ri j=1;j<i;++j)b[sg[j-1]^sg[i-j-1]]=0;
		sg[i]=b._Find_first();
		if(sg[i]>99)sg[i]=0;
	}
	for(ri i=1000;i<=500000;++i)sg[i]=sg[i-68];
	return 67942;
}(sg);
int n,t_case;
char s[maxn];
int main(){
	assert(init==67942);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		ri ans=0,cntb=0,cntr=0,lst=1;
		for(ri i=1;i<=n;++i){
			if(s[i]=='B')++cntb;
			else ++cntr;
			if(s[i]==s[i-1])ans^=sg[i-lst],lst=i;
		}
		ans^=sg[n+1-lst];
		if(cntb!=cntr)puts(cntb<cntr?"Alice":"Bob");
		else puts(ans?"Alice":"Bob");
	}
	return 0;
}