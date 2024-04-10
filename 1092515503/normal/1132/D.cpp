#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e13;
int n,m,l,r=INF;
struct pii{
	int tim,x,y;
	friend bool operator <(const pii &u,const pii &v){
		if(u.tim!=v.tim)return u.tim>v.tim;
		if(u.y!=v.y)return u.y<v.y;
		return u.x>v.x;
	}
}p[200100],t;
priority_queue<pii>q;
inline bool che(int ip){
	while(!q.empty())q.pop();
	for(register int i=1;i<=n;i++)if(p[i].tim<m)q.push(p[i]);//this cut branch really can help you a lot!!!
	for(register int i=0;i<m;i++){
		if(q.empty())return true;
		t=q.top(),q.pop();
//		printf("%d\n",t<q.top()); 
//		printf("%lld %lld\n",t.x,t.y);
		if(t.tim<i)return false;
		t.x+=ip,t.tim=t.x/t.y;
		if(t.tim<m)q.push(t);
	}
	return true;
}
inline void read(int &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
signed main(){
	read(n),read(m);
	for(register int i=1;i<=n;i++)read(p[i].x);
	for(register int i=1;i<=n;i++)read(p[i].y),p[i].tim=p[i].x/p[i].y;
	while(l<r){
		int mid=(l+r)>>1;
//		printf("%lld %lld %lld\n",l,r,mid);
		if(che(mid))r=mid;
		else l=mid+1;
	}
	printf("%lld\n",(r==INF)?-1:r);
	return 0;
}
/*
3 20
8 9 10
9 2 10
*/