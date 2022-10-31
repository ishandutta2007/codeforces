#include<bits/stdc++.h>
#define N 200100
using namespace std;
int a[N],in[N],fr[N];
bool vis[N],inc[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,ans;
		scanf("%d",&n);
		ans=n;
		for(int i=1;i<=n;i++) in[i]=0,vis[i]=false,inc[i]=false,fr[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			in[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(in[i]==0){
				ans--;
				vis[i]=true;
				int u=a[i],p=i;
				for(u=a[i];!vis[u];p=u,u=a[u]){
					fr[u]=p;
					vis[u]=true;
				}
				if(inc[u]){
					a[fr[u]]=i;
					fr[i]=fr[u];
					fr[u]=p;
				}
				else{
					a[p]=i;
					fr[i]=p;
				}
				for(u=i;!inc[u];u=a[u]){
					inc[u]=true;
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}