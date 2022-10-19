#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef unsigned long long ll;
const int base=2333,maxn=11;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int m,n;
vector<int>a[maxn];
map<ll,bool>ban,vis;
struct node{
	int pos[maxn];
	ll sum;
	inline bool operator<(const node &k)const{
		return sum<k.sum;
	}
	inline ll gethsh(){
		ll hsh=0;
		for(ri i=1,x;i<=n;++i)hsh=hsh*base+pos[i];
		return hsh;
	}
}tmp;
priority_queue<node>q;
int main(){
	scanf("%d",&n);
	for(ri i=1,x,y;i<=n;++i){
		scanf("%d",&x);
		a[i]={0};
		tmp.pos[i]=x;
		while(x--)scanf("%d",&y),a[i].push_back(y);
		tmp.sum+=a[i].back();
	}
	scanf("%d",&m);
	while(m--){
		ll hsh=0;
		for(ri i=1,x;i<=n;++i)scanf("%d",&x),hsh=hsh*base+x;
		ban[hsh]=true;
	}
	q.push(tmp);
	vis[tmp.gethsh()]=true;
	while(1){
		node p=q.top();
		if(!ban[p.gethsh()])break;
		q.pop();
		for(ri i=1;i<=n;++i)
			if(p.pos[i]>1){
				node tmp=p;
				tmp.sum-=a[i][tmp.pos[i]];
				--tmp.pos[i];
				tmp.sum+=a[i][tmp.pos[i]];
				if(!vis[tmp.gethsh()]){
					q.push(tmp);
					vis[tmp.gethsh()]=true;
				}
			}
	}
	for(ri i=1;i<=n;++i)printf("%d ",q.top().pos[i]);
	return 0;
}