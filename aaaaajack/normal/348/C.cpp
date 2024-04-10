#include<bits/stdc++.h>
#define N 100100
#define S 350
using namespace std;
vector<int> e[N];
vector<int> in[N];
int bigsz;
vector<int> ins[N];
map<int,int> big_id;
long long a[N];
long long bigadd[N],bigsum[N];
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		e[i].resize(k);
		for(int j=0;j<k;j++) scanf("%d",&e[i][j]);
		if(k>S){
			big_id[i]=bigsz;
			for(int j=0;j<k;j++){
				in[e[i][j]].push_back(bigsz);
				bigsum[bigsz]+=a[e[i][j]];
			}
			bigsz++;
		}
	}
	for(int i=1;i<=m;i++){
		ins[i].resize(bigsz,0);
		for(auto x:e[i]){
			for(auto j:in[x]){
				ins[i][j]++;
			}
		}
	}
	while(q--){
		char tp;
		scanf(" %c",&tp);
		if(tp=='?'){
			long long ans=0;
			int x;
			scanf("%d",&x);
			if(e[x].size()>S){
				ans=bigsum[big_id[x]];
			}
			else{
				for(auto y:e[x]){
					ans+=a[y];
				}
			}
			for(int i=0;i<bigsz;i++){
				ans+=bigadd[i]*ins[x][i];
			}
			printf("%I64d\n",ans);
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			if(e[x].size()>S){
				bigadd[big_id[x]]+=y;
			}
			else{
				for(int i=0;i<bigsz;i++){
					bigsum[i]+=1LL*y*ins[x][i];
				}
				for(auto i:e[x]){
					a[i]+=y;
				}
			}
		}
	}
	return 0;
}