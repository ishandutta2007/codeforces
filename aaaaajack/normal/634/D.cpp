#include<cstdio>
#include<algorithm>
#include<deque>
#define N 200100
using namespace std;
struct gas{
	int x,v;
	bool operator<(gas r)const{return x<r.x;}
}g[N],s[N],tmp;
int main(){
	int d,n,m,sz,pre;
	long long ans=0;
	scanf("%d%d%d",&d,&n,&m);
	g[0].x=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&g[i].x,&g[i].v);
	}
	sort(g+1,g+m+1);
	g[m+1].x=d;
	bool wrong=false;
	int tmp=0,add;
	deque<int> r;
	int now=0,l=0;
	while(now<m+1){
		if(tmp<now+1) tmp=now+1;
		while(tmp<=m+1&&g[tmp].x<=g[now].x+n){
			while(!r.empty()&&g[tmp].v<=g[r.back()].v) r.pop_back();
			r.push_back(tmp++);
			if(r.size()==1&&g[r.front()].v<g[now].v) break;
		}
		if(r.empty()){
			wrong=true;
			break;
		}
		if(g[now].v<g[r.front()].v){
			ans+=1LL*g[now].v*(n-l);
			l=n-(g[r.front()].x-g[now].x);
		}
		else{
			ans+=1LL*g[now].v*(g[r.front()].x-g[now].x-l);
			l=0;
		}
		now=r.front();
		r.pop_front();
	}
	if(wrong) puts("-1");
	else printf("%I64d\n",ans);
	return 0;
}