#include<bits/stdc++.h>
using namespace std;
int T,n,m,occ[100100],res[100100];
vector<int>v[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)occ[i]=0;
		for(int i=1,x,y;i<=m;i++){
			v[i].clear(),scanf("%d",&x);
			while(x--)scanf("%d",&y),v[i].push_back(y);
			if(v[i].size()==1)occ[v[i][0]]++,res[i]=v[i][0];
		}
		for(int i=1;i<=m;i++){
			if(v[i].size()==1)continue;
			int mnp=v[i][0];for(auto j:v[i])if(occ[j]<occ[mnp])mnp=j;
			res[i]=mnp,occ[mnp]++;
		}
		bool ok=true;
		for(int i=1;i<=n;i++)if(occ[i]>(m+1)/2){ok=false;break;}
		if(!ok){puts("NO");continue;}
		puts("YES");
		for(int i=1;i<=m;i++)printf("%d ",res[i]);puts("");
	}
	return 0;
}