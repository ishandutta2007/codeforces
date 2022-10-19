#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e5+10;
int a[maxn],m,n,t_case;
ll ans;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>pos[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)
		for(ri j=1,x;j<=m;++j){
			scanf("%d",&x);
			pos[x].emplace_back(i,j);
		}
	for(ri i=1;i<=100000;++i)
		if(pos[i].size()){
			map<int,int>cnt;
			for(const pii &j:pos[i])++cnt[j.fi];
			ri pre=0;
			for(const pii &j:cnt){
				ans+=1ll*pre*j.fi*j.se;
				pre+=j.se;
				ans-=1ll*(pos[i].size()-pre)*j.fi*j.se;
			}
			map<int,int>().swap(cnt);
			for(const pii &j:pos[i])++cnt[j.se];
			pre=0;
			for(const pii &j:cnt){
				ans+=1ll*pre*j.fi*j.se;
				pre+=j.se;
				ans-=1ll*(pos[i].size()-pre)*j.fi*j.se;
			}
		}
	printf("%lld",ans);
	return 0;
}