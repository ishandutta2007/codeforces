#include <stdio.h>

int p[200001];
bool vis[200001];
int n;

void DFS(int node, int pa)
{
	if(node==pa) return;
	vis[node]=true;
	DFS(p[node],pa);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",p+i);
	bool flag=false;
	int num, sum=0;
	for(int i=0;i<n;i++) {
		scanf("%d",&num);
		sum+=num;
	}


	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=true;
			DFS(p[i],i);
			cnt++;
		}
	}
	if(cnt==1) cnt=0;
	cnt+=((sum+1)%2);
	printf("%d\n",cnt);

	return 0;
}