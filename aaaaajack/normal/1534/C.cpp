#include<bits/stdc++.h>
#define Q 1000000007
int a[400100],e[400100];
bool vis[400100];
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,r=1;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++) scanf("%d",&e[a[i]]);
		for(int i=1;i<=n;i++) vis[i]=false;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				r=(r+r)%Q;
				for(int j=i;!vis[j];j=e[j]){
					vis[j]=true;
				}
			}
		}
		printf("%d\n",r);
	}
	return 0;
}