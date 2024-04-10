#include<bits/stdc++.h>
using namespace std;
map<long long,long long> fee;
int main(){
	int q,tp;
	long long u,v,w;
	scanf("%d",&q);
	while(q--){
		scanf("%d%I64d%I64d",&tp,&u,&v);
		if(tp==1){
			scanf("%I64d",&w);
			while(u!=v){
				if(u>v){
					fee[u]+=w;
					u>>=1;
				}
				else{
					fee[v]+=w;
					v>>=1;
				}
			}
		}
		else{
			long long ans=0;
			while(u!=v){
				if(u>v){
					ans+=fee[u];
					u>>=1;
				}
				else{
					ans+=fee[v];
					v>>=1;
				}
			}
			printf("%I64d\n",ans);
		}
	}
	return 0;
}