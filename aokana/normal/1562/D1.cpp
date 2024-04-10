#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=3e5+10;
int a[maxn],b[maxn],bl,m,n,pre[maxn],t_case;
char s[maxn];
vector<int>pos[maxn*4];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%s",&n,&m,s+1);
		for(ri i=0;i<=n*4;++i)pos[i].clear();
		for(ri i=1;i<=n;++i){
			a[i]=(s[i]=='+'?1:-1);
			pre[i]=pre[i-1]+((i&1)?a[i]:-a[i]);
			pos[pre[i]+pre[i-1]+n*2].push_back(i);
		}
		while(m--){
			ri l,r;
			scanf("%d%d",&l,&r);
			if(pre[r]-pre[l-1]==0)puts("0");
			else{
				ri sum=pre[r]+pre[l-1]+n*2,tmp=lower_bound(pos[sum].begin(),pos[sum].end(),l)-pos[sum].begin();
				if(tmp>=pos[sum].size()||pos[sum][tmp]>r)puts("2");
				else puts("1");
			}
		}
	}
	return 0;
}