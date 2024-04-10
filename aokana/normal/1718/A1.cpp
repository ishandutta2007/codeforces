#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],f[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			a[i]^=a[i-1];
		}
		map<int,int>p;
		p[0]=0;
		for(ri i=1;i<=n;++i){
			f[i]=f[i-1]+1;
			auto it=p.find(a[i]);
			if(it!=p.end())ckmin(f[i],f[it->second]+i-it->second-1);
			p[a[i]]=i;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}