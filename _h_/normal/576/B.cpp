#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	int n;
	scanf("%d",&n);
	vector<int> p(n+1);
	rep(i,1,n+1){
		scanf("%d",&p[i]);
		if(p[i] == i){
			puts("YES");
			rep(j,1,n+1)
				if(j != i)
					printf("%d %d\n",i,j);
			return 0;
		}
	}
	bool flag = 0;
	int good = -1;
	vector<bool> vis(n+1);
	rep(i,1,n+1){
		if(!vis[i]){
			int j = i, cnt = 0;
			do{
				vis[j] = 1;
				++cnt;
				j = p[j];
			}while(j != i);
			if(cnt == 2)
				good = i;
			flag |= cnt & 1;
		}
	}
	if(good != -1 && !flag){
		puts("YES");
		fill(vis.begin(),vis.end(),0);
		int doog = p[good];
		vis[doog] = vis[good] = 1;
		printf("%d %d\n",good,doog);
		rep(i,1,n+1)
			if(!vis[i]){
				bool par = 0;
				int j = i;
				do{
					vis[j] = 1;
					printf("%d %d\n",j,par ? good : doog);
					par ^= 1;
					j = p[j];
				}while(j != i);
			}
	}
	else
		puts("NO");
}