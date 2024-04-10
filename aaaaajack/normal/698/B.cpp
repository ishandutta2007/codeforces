#include<bits/stdc++.h>
#define N 200100
using namespace std;
bool vis[N];
bool ch[N];
int p[N],stk[N],cnt;
int main(){
	int n,fx=0,rt=-1,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cnt=0;
			int u=i,sz=1;
			while(!vis[u]){
				stk[cnt++]=u;
				vis[u]=true;
				u=p[u];
			}
			while(cnt&&stk[cnt-1]!=u) --cnt,sz++;
			if(cnt){
				if(rt<0||sz==1) rt=u;
				ch[u]=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(ch[i]&&p[i]!=rt){
			p[i]=rt;
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
	puts("");
	return 0;
}