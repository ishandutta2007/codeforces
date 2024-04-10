#include<bits/stdc++.h>
using namespace std;
int f[20][1<<10];
int main(){
	int n;
	scanf("%d",&n);
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<20;i++){
		vector<int> v;
		for(int j=0;j<n;j++){
			if(((j>>i/2)&1)!=(i&1)){
				v.push_back(j+1);
			}
		}
		if(v.empty()) continue;
		printf("%d\n",v.size());
		for(int j=0;j<v.size();j++){
			if(j) putchar(' ');
			printf("%d",v[j]);
		}
		puts("");
		fflush(stdout);
		for(int j=0;j<n;j++){
			scanf("%d",&f[i][j]);
		}
	}
	puts("-1");
	for(int i=0;i<n;i++){
		int ans=1e9+7;
		for(int j=0;j<10;j++){
			if(i&(1<<j)) ans=min(ans,f[j<<1|1][i]);
			else ans=min(ans,f[j<<1][i]);
		}
		printf("%d ",ans);
	}
	puts("");
	return 0;
}