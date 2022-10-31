#include<bits/stdc++.h>
#define N 200100
using namespace std;
int out[N];
int main(){
	int n,m,q,x,y,tp;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		out[x]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(out[i]==0) ans++;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&tp);
		if(tp==3){
			printf("%d\n",ans);
		}
		else{
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			if(tp==1){
				if(!out[x]) ans--;
				out[x]++;
			}
			else{
				out[x]--;
				if(!out[x]) ans++;
			}
		}
	}
	return 0;
}