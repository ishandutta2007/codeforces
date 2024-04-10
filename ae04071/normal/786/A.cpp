#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>

typedef std::pair<int, int> ip;
int n, k[2], arr[2][7000];
int deg[2][7000], cache[2][7000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<2;i++) {
		scanf("%d",k+i);
		for(int j=0;j<k[i];j++)
			scanf("%d",&arr[i][j]);
	}

	for(int i=0;i<2;i++) {
		for(int j=1;j<n;j++) {
			deg[i][j]=k[i];
		}
	}

	std::queue<ip> que;
	que.push(ip(0,0));
	que.push(ip(1,0));

	while(!que.empty()) {
		ip from=que.front();que.pop();
		int next=from.first^1;
		for(int i=0;i<k[next];i++) {
			int to=(from.second-arr[next][i]+n+n)%n;

			if(cache[next][to]==1) continue;

			if(cache[from.first][from.second]==1) {
				--deg[next][to];
				if(deg[next][to]==0) {
					que.push(ip(next,to));
				}
			}
			else {
				cache[next][to]=1;
				que.push(ip(next,to));
			}
		}
	}
	for(int i=0;i<2;i++) {
		for(int j=1;j<n;j++) {
			if(cache[i][j]==1) printf("Win ");
			else if(deg[i][j]>0) printf("Loop ");
			else printf("Lose ");
		}
		puts("");
	}

	return 0;
}