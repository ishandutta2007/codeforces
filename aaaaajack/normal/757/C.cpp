#include<bits/stdc++.h>
#define Q 1000000007
using namespace std;
vector<int> in[1001000];
int id[1001000];
bool cmp(int a,int b){
	if(in[a].size()<in[b].size()) return true;
	if(in[a].size()>in[b].size()) return false;
	for(int i=0;i<in[a].size();i++){
		if(in[a][i]<in[b][i]) return true;
		if(in[a][i]>in[b][i]) return false;
	}
	return false;
}
int main(){
	int n,m,g,x,ans=1,pre=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) id[i]=i;
	for(int i=0;i<n;i++){
		scanf("%d",&g);
		while(g--){
			scanf("%d",&x);
			in[x].push_back(i);
		}
	}
	sort(id+1,id+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i==1||!cmp(id[i-1],id[i])) pre++;
		else pre=1;
		ans=1LL*ans*pre%Q;
	}
	printf("%d\n",ans);
	return 0;
}