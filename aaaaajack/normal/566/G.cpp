#include<cstdio>
#include<algorithm>
#include<utility>
#define px first
#define py second
#define N 100100
using namespace std;
pair<int,int> a[N],b[N],v[N];
int sz;
long long cross(pair<int,int> a,pair<int,int> b,pair<int,int> c){
	return 1LL*(b.first-a.first)*(c.second-a.second)-1LL*(b.second-a.second)*(c.first-a.first);
}
int main(){
	int n,m,x,y,now=0;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].px,&a[i].py);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&b[i].px,&b[i].py);
	}
	sort(a,a+n);
	sort(b,b+m);
	for(int i=0;i<m;i++){
		while(sz&&v[sz-1].py<=b[i].py||sz>=2&&cross(v[sz-2],v[sz-1],b[i])>=0) sz--;
		v[sz++]=b[i];
	}
	bool win=true;
	for(int i=0;i<n;i++){
		while(now<sz&&a[i].px>=v[now].px) now++;
		if(now==0){
			if(a[i].py>=v[0].py) win=false;
		}
		else if(now==sz) win=false;
		else if(cross(a[i],v[now-1],v[now])>=0) win=false;
	}
	if(win) puts("Min");
	else puts("Max");
	return 0;
}