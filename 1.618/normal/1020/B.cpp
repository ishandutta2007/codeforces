#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1005
using namespace std;
typedef long long ll;
int n,p[maxn],ans[maxn];
bool vis[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		int u = i;
		while(!vis[u]){
			vis[u] = true;
			u = p[u];
		}
		ans[i] = u;
	}
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
		if(i == n) printf("\n");
		else printf(" ");
	}
	return 0;
}