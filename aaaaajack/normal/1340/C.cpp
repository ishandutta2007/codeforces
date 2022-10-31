/* in the name of Anton */
#include<bits/stdc++.h>
#define N 1000010
#define M 10010
#define K 1010
#define all(x) begin(x),end(x)
using namespace std;
int d[K][M];
int a[M];
const int inf=1<<30;
bitset<M> vis[K];
vector<int> que[K]; 
int main(){
	int n,m,gt,rt,ans=inf;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+m);
	m=unique(a,a+m)-a;
	scanf("%d%d",&gt,&rt);
	for(int i=0;i<gt;i++) fill(d[i],d[i]+M,inf);
	que[0].push_back(0);
	d[0][0]=0;
	vis[0][0]=true;
	for(int p=0;!que[0].empty();p++){
		for(int i=0;i<gt;i++){
			for(auto x:que[i]){
				if(x+1<m && i+a[x+1]-a[x]<=gt){
					int nxt=i+a[x+1]-a[x];
					if(!vis[nxt][x+1]){
						que[nxt].push_back(x+1);
						vis[nxt][x+1]=true;
						d[nxt%gt][x+1]=p*(gt+rt)+nxt;
					}
				}
				if(x>0 && i+a[x]-a[x-1]<=gt){
					int nxt=i+a[x]-a[x-1];
					if(!vis[nxt][x-1]){
						que[nxt].push_back(x-1);
						vis[nxt][x-1]=true;
						d[nxt%gt][x-1]=p*(gt+rt)+nxt;
					}
				}
			}
			que[i].clear();
		}
		que[0]=que[gt];
		que[gt].clear();
	}
	int mn=inf;
	for(int i=0;i<gt;i++){
		if(d[i][m-1]<mn) mn=d[i][m-1];
	}		
	if(mn==inf) puts("-1");
	else printf("%d\n",mn);
	return 0;
}