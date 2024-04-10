#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=3e5+10,maxp=567;
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    inline size_t operator()(uint64_t x)const{
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
int a[maxn],b[maxn],bl,cnt[maxn],m,n,t_case;
unordered_set<int,custom_hash>ban[maxn];
vector<int>pos[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		bl=unique(b+1,b+n+1)-b-1;
		for(ri i=1;i<=n;++i)++cnt[a[i]=lower_bound(b+1,b+bl+1,a[i])-b],pos[i].clear();
		for(ri i=1;i<=bl;++i)ban[i].clear(),pos[cnt[i]].push_back(i);
		for(ri i=1;i<=n;++i)sort(pos[i].begin(),pos[i].end(),greater<int>());
		while(m--){
			ri x,y;
			scanf("%d%d",&x,&y);
			ri px=lower_bound(b+1,b+bl+1,x)-b,py=lower_bound(b+1,b+bl+1,y)-b;
			if(px>bl||b[px]!=x||py>bl||b[py]!=y)continue;
			ban[px].insert(py),ban[py].insert(px);
		}
		ll ans=0;
		for(ri i=1;i<=n;++i)
			for(ri j:pos[i])
				for(ri k=1;k<=i;++k)
					for(ri l:pos[k])
						if(j!=l&&!ban[j].count(l)){
							ckmax(ans,1ll*(i+k)*(b[j]+b[l]));
							break;
						}
		printf("%lld\n",ans);
		clear(cnt,bl);
	}
	return 0;
}