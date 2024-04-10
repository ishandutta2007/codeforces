#include<cstdio>
#include<map>
#include<algorithm>
#define N 200100
using namespace std;
map<int,int> ed[N];
int rt[N],sz[N];
void merge(int x,int y){
	x=rt[x],y=rt[y];
	if(x==y) return;
	if(sz[x]<sz[y]) swap(x,y);
	for(auto it=ed[y].begin();it!=ed[y].end();++it){
		for(int i=it->first;i<it->second;i++){
			rt[i]=x;
			sz[x]++;
		}
		map<int,int>::iterator nit=ed[x].lower_bound(it->second),pit=nit,tit;
		if(nit!=ed[x].begin()&&(--pit)->second==it->first){
			pit->second=it->second;
			tit=pit;
		}
		else tit=ed[x].insert(*it).first;
		if(nit!=ed[x].end()&&tit->second==nit->first){
			tit->second=nit->second;
			ed[x].erase(nit);
		}
	}
}
int main(){
	int n,q,t,x,y;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) ed[i][i]=i+1,rt[i]=i,sz[i]=1;
	while(q--){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			merge(x,y);
		}
		else if(t==2){
			while(1){
				auto it=ed[rt[x]].upper_bound(x);
				--it;
				if(it->second<=y){
					merge(x,it->second);
				}
				else break;
			}
		}
		else{
			if(rt[x]==rt[y]) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}