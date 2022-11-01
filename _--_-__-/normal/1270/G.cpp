//by dxm
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

int n,a[1000005],deg[1000005];
void solve(){
	scanf("%d",&n);
	rep1(i,n)scanf("%d",&a[i]);
	rep1(i,n)a[i]=i-a[i];
	rep1(i,n)deg[i]=0;
	rep1(i,n)deg[a[i]]++;
	queue<int>que;
	rep1(i,n)if(deg[i]==0)que.push(i);
	while(!que.empty()){int v=que.front();que.pop();deg[a[v]]--;if(deg[a[v]]==0)que.push(a[v]);}
	int cur=-1;
	rep1(i,n)if(deg[i]>0)cur=i;
	vector<int>ans;
	int nc=cur;do{ans.push_back(nc);nc=a[nc];}while(nc!=cur);
	printf("%d\n",ans.size());rep(i,ans.size())printf("%d ",ans[i]);printf("\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}