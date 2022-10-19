#include<bits/stdc++.h>
using namespace std;
struct apple{
	int x,p,wz;
	bool operator<(const apple &other)const{
		return x<other.x;
	}
}e[200005];
long long gx[200005];
int v[200005],vv[200005];
int main(){
	int T=1;
	cin>>T;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int mxp=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d",&e[i].x,&e[i].p);
			e[i].wz=i;
			mxp=max(mxp,e[i].p);
		}
		for(int i=1;i<=n;++i)gx[i]=0,v[i]=1;
		sort(e+1,e+n+1);
		priority_queue<int,vector<int>,greater<int>>pq;
		int cz;
		long long he;
		while(pq.size())pq.pop();
		cz=0;
		he=0;
		for(int i=1;i<=n;++i){
			pq.emplace(e[i].p+cz);
			he+=e[i].p+cz;
			while(pq.size()&&pq.top()<=cz){
				int x=pq.top();
				he-=x;
				pq.pop();
			}
			gx[i]+=he-1ll*pq.size()*cz;
			cz+=e[i+1].x-e[i].x;
		}
		while(pq.size())pq.pop();
		cz=0;
		he=0;
		for(int i=n;i>=1;--i){
			pq.emplace(e[i].p+cz);
			he+=e[i].p+cz;
			while(pq.size()&&pq.top()<=cz){
				int x=pq.top();
				he-=x;
				pq.pop();
			}
			gx[i]+=he-1ll*pq.size()*cz;
			cz+=e[i].x-e[i-1].x;
		}
		for(int i=1;i<=n;++i)gx[i]-=e[i].p;
		int flag=0;
		for(int i=1;i<=n;++i)if(gx[i]>m){
			long long cc=gx[i]-m;
			if(cc>mxp){
				flag=1;
				break;
			}
		}
		if(flag){
			for(int i=1;i<=n;++i)putchar('0');
			putchar('\n');
			continue;
		}
		priority_queue<pair<int,int>>pq1;
		for(int i=1;i<=n;++i){
			pq1.emplace(-e[i].p-e[i].x,i);
			if(gx[i]<=m)continue;
			int cc=gx[i]-m;
			while(pq1.size()){
				auto au=pq1.top();
				if(-au.first<e[i].x+cc){
					v[au.second]=0;
					pq1.pop();
				}else break;
			}
		}
		priority_queue<pair<int,int>>pq2;
		for(int i=n;i>=1;--i){
			pq2.emplace(-e[i].p+e[i].x,i);
			if(gx[i]<=m)continue;
			int cc=gx[i]-m;
			while(pq2.size()){
				auto au=pq2.top();
				if(-au.first<-e[i].x+cc){
					v[au.second]=0;
					pq2.pop();
				}else break;
			}
		}
		for(int i=1;i<=n;++i)vv[e[i].wz]=v[i];
		for(int i=1;i<=n;++i)putchar(vv[i]+'0');
		putchar('\n');
	}
	return 0;
}