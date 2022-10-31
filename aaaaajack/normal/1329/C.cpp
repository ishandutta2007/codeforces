#include<bits/stdc++.h>
using namespace std;
int a[1<<22],sz[1<<22],pop[1<<22];
list<int> cand[1<<22];
struct cmp{
	bool operator()(int i,int j)const{
		return a[i]<a[j];
	}
};
int main(){
	int t,g,h;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&h,&g);
		for(int i=1;i<(1<<h);i++){
			scanf("%d",&a[i]);
			if(i<(1<<g)) sz[i]=1;
			else sz[i]=0;
			pop[i]=1;
		}
		for(int i=(1<<g)-1;i>1;i--){
			sz[i/2]+=sz[i];
		}
		for(int i=(1<<h-1);i<(1<<h);i++){
			cand[i].push_back(i);
		}
		for(int i=(1<<h-1)-1;i>0;i--){
			list<int> tmp;
			auto it=cand[i*2].begin();
			advance(it,sz[i*2]);
			cand[i].splice(cand[i].end(),cand[i*2],cand[i*2].begin(),it);
			it=cand[i*2+1].begin();
			advance(it,sz[i*2+1]);
			cand[i].splice(cand[i].end(),cand[i*2+1],cand[i*2+1].begin(),it);
			int mx=0;
			for(auto x:cand[i]){
				mx=max(mx,a[x]);
			}
			//printf("mx=%d\n",mx);
			cand[i*2].merge(cand[i*2+1],cmp());
			it=cand[i*2].begin();
			while(it!=cand[i*2].end() && a[*it]<mx){
				it=cand[i*2].erase(it);
			}
			cand[i].splice(cand[i].end(),cand[i*2]);
			cand[i].push_back(i);
			//for(auto x:cand[i]){
			//	printf("%d ",a[x]);
			//}
			//printf(" <--- heap %d\n",i);
		}
		long long ans=0;
		for(int i=1;i<(1<<g);i++){
			pop[cand[1].front()]=0;
			ans+=a[cand[1].front()];
			cand[1].pop_front();
		}
		printf("%lld\n",ans);
		for(int i=(1<<h)-1;i>0;i--){
			if(pop[i]) printf("%d ",i);
		}
		puts("");
		cand[1].clear();
		for(int i=1;i<(1<<h);i++) assert(cand[i].empty());
	}
	return 0;
}