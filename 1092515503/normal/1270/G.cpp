#include<bits/stdc++.h>
using namespace std;
int T,n,a[1001000];
bool vis[1001000];
vector<int>v;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]=i-x;
		int i=1;
		for(;!vis[i];i=a[i])vis[i]=true;
		for(;vis[i];i=a[i])v.push_back(i),vis[i]=false;
		printf("%d\n",v.size());
		for(auto x:v)printf("%d ",x);puts("");
		v.clear();
		for(int i=1;i<=n;i++)vis[i]=false;		
	}
	return 0;
}