#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
int T,n,m,k;
gp_hash_table<int,bool>s[100100];
queue<int>p,q;
bool che(int x){
	for(auto i=s[x].begin();i!=s[x].end();i++){
		auto j=i;j++;
		for(;j!=s[x].end();j++)if(s[j->first].find(i->first)==s[j->first].end())return false;
	}
	puts("2");for(auto i:s[x])printf("%d ",i.first);printf("%d\n",x);
	return true;
}
void Q(){
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto y:s[x]){
			s[y.first].erase(x);
			if(s[y.first].size()<k-1)q.push(y.first);
			if(s[y.first].size()==k-1)p.push(y.first);
		}
		s[x].clear();
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)s[i].clear();
		for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),s[x][y]=true,s[y][x]=true;
		if((1ll*(k-1)*k>>1)>m){puts("-1");continue;}
		if(k==1){puts("2"),puts("1");continue;}
		for(int i=1;i<=n;i++)if(s[i].size()<k-1)q.push(i);
		Q();
		while(!p.empty())p.pop();
		for(int i=1;i<=n;i++)if(s[i].size()==k-1)p.push(i);
		bool ok=false;
		while(!p.empty()){
			int x=p.front();p.pop();
			if(s[x].size()!=k-1)continue;
			if(che(x)){ok=true;break;}
			for(auto y:s[x]){
				s[y.first].erase(x);
				if(s[y.first].size()<k-1)q.push(y.first);
				if(s[y.first].size()==k-1)p.push(y.first);
			}
			Q();
		}
		if(ok)continue;
		vector<int>u;
		for(int i=1;i<=n;i++)if(s[i].size()>=k)u.push_back(i);
		if(u.empty()){puts("-1");continue;}
		printf("1 %d\n",u.size());
		for(auto i:u)printf("%d ",i);puts("");
	}
	return 0;
}