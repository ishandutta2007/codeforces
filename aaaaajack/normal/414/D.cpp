#include<cstdio>
#include<vector>
#define N 100010
using namespace std;
vector<int> g[N];
int count[N]={0};
void DFS(int now,int depth,int from){
	int i;
	count[depth]++;
	for(i=0;i<g[now].size();i++){
		if(g[now][i]==from) continue;
		DFS(g[now][i],depth+1,now);
	}
}
int main(){
	int m,k,p,i,j,x,y,ans=0,temp;
	long long coin=0,water=0;
	scanf("%d%d%d",&m,&k,&p);
	for(i=0;i<m-1;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	DFS(1,0,0);
	for(i=m-1,j=m-1;i>=1;i--){
		if(j>i){
			j=i;
			coin=0;
			water=0;
		}
		while(j>=1 && coin+1LL*(i-j)*count[j]<=p && water+count[j]<=k){
			coin+=count[j]*(i-j);
			water+=count[j];
			j--;
		}
		temp=water;
		if(j>=1){
			if(j==i) temp=k;
			else if((p-coin)/(i-j)<(k-water)) temp+=(p-coin)/(i-j);
			else temp+=(k-water);
		}
		if(temp>ans) ans=temp;
		water-=count[i];
		coin-=water;
	}
	printf("%d\n",ans);
	return 0;
}