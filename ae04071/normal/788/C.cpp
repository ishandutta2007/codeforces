#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

int n,k;
int a[1000000];

std::vector<int> adj[2001];
bool vis[2001];
int dist[2001];

int main() {
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++)
		scanf("%d",a+i);

	std::sort(a,a+k);
	std::vector<int> arr;
	for(int i=0;i<k;i++)
		if(i==0||a[i]!=a[i-1]) arr.push_back(a[i]-n);

	for(int i=0;i<=2000;i++) {
		for(int j=0;j<arr.size();j++) {
			int val=i+arr[j];
			if(val>=0 && val<=2000) {
				adj[i].push_back(val);
			}
		}
	}

	std::queue<int> que;
	que.push(1000);
	vis[1000]=true;

	while(!que.empty()) {
		int now=que.front();que.pop();
		for(auto &it:adj[now]) {
			if(!vis[it]) {
				vis[it]=true;
				que.push(it);
				dist[it]=dist[now]+1;
			}
			else if(it==1000) {
				printf("%d\n",dist[now]+1);
				return 0;
			}
		}
	}

	printf("-1\n");
	return 0;


	return 0;
}