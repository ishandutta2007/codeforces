#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,A,H,pov[40],m;
unordered_map<int,vector<int> >u[1<<4],v[1<<4];
vector<int>qwq,qaq;
void solve(int val,bool tp){
	if(qaq.size()==1){
		int x=qaq.back();
//		printf("%d %d %d\n",tp,x,val);
//		for(auto i:qwq)printf("%d ",i);puts("");
		if(tp)x-=m+1;else x--;
		if(!tp&&u[x].find(val)==u[x].end())u[x][val]=qwq;
		if(tp&&v[x].find(val)==v[x].end())v[x][val]=qwq;
		return; 
	}
	auto QWQ=qwq,QAQ=qaq;int VAL=val;
	int lim=(QAQ.size()>>1);
	for(int i=0;i<(1<<lim);i++){
		qaq.clear();
		for(int j=0;j<lim;j++){
			int wn=QAQ[j<<1|((i>>j)&1)],ls=QAQ[j<<1|!((i>>j)&1)];
			qwq[ls-(tp?m+1:1)]=QAQ.size()+1,val=(1ll*ls*pov[QAQ.size()+1]+val)%mod;
			qaq.push_back(wn);
		}
		solve(val,tp);
		qaq=QAQ,qwq=QWQ,val=VAL;
	}
}
int main(){
	scanf("%d%d%d",&n,&A,&H),m=(1<<(n-1));
	pov[0]=1;for(int i=1;i<=(1<<n);i++)pov[i]=1ll*pov[i-1]*A%mod;
//	for(int i=0;i<=(1<<n);i++)printf("%d ",pov[i]);puts("");
	qwq.resize(m),qaq.resize(m);
	for(int i=0;i<m;i++)qaq[i]=i+1;
	solve(0,false);
	for(int i=0;i<m;i++)qaq[i]=m+i+1;
	solve(0,true);
	for(int i=0;i<m;i++){
		int val,lav;
		for(auto x:u[i]){
//			printf("%d:%d\n",i,x.first);
			for(int j=0;j<m;j++){
				val=(1ll*(i+1)*pov[1]+1ll*(j+m+1)*pov[2])%mod;
				lav=(0ll+H+mod-val+mod-x.first)%mod;
				if(v[j].find(lav)!=v[j].end()){
					vector<int>w;
					for(auto k:x.second)w.push_back(k);
					for(auto k:v[j][lav])w.push_back(k);
					w[i]=1;
					w[m+j]=2;
					for(auto k:w)printf("%d ",k);puts("");
					return 0;
				}
				val=(1ll*(i+1)*pov[2]+1ll*(j+m+1)*pov[1])%mod;
				lav=(0ll+H+mod-val+mod-x.first)%mod;
				if(v[j].find(lav)!=v[j].end()){
					vector<int>w;
					for(auto k:x.second)w.push_back(k);
					for(auto k:v[j][lav])w.push_back(k);
					w[i]=2;
					w[m+j]=1;
					for(auto k:w)printf("%d ",k);puts("");
					return 0;
				}	
			}
		}
	}
	puts("-1");
	return 0;
}