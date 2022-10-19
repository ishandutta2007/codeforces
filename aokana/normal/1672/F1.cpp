#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],ans[maxn],m,n,t_case;
set<int>pos[maxn];
multiset<int>s;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)pos[i].clear();
		s.clear();
		for(ri i=1;i<=n;++i)scanf("%d",a+i),ans[i]=i,pos[a[i]].insert(i),s.insert(a[i]);
		while(s.size()){
			ri x=*s.begin();s.erase(s.begin());
			ri cur=*pos[x].begin();pos[x].erase(pos[x].begin());
			auto it=s.upper_bound(x);
			while(it!=s.end()){
				ri y=*it;s.erase(it);
				ri nxt=*pos[y].begin();pos[y].erase(pos[y].begin());
				swap(ans[cur],ans[nxt]);
				x=y,cur=nxt,it=s.upper_bound(x);
			}
		}
		for(ri i=1;i<=n;++i)printf("%d ",a[ans[i]]);
		printf("\n");
	}
	return 0;
}