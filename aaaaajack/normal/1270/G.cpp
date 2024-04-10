#include<bits/stdc++.h>
#define N 1001000
using namespace std;
int a[N];
bool vis[N];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			vis[i]=false;
			a[i]=i-a[i];
		}
		vector<int> stk,ans;
		int u,v;
		for(u=1;!vis[u];u=a[u]){
			vis[u]=true;
			stk.push_back(u);
		}
		do{	
			v=stk.back();
			ans.push_back(v);
			stk.pop_back();
		}while(v!=u);
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();i++){
			printf("%d%c",ans[i],i<ans.size()-1?' ':'\n');
		}
	}
	return 0;
}