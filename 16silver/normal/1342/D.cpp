#include <bits/stdc++.h>
using namespace std;
int p[200002],q[200002],r[200002];
vector<int> tmp[200002];
int main(){
	int n,k;
	int ans=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		p[t]++;
	}
	for(int i=k;i>=1;i--){
		q[i]=q[i+1]+p[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&r[i]);
		ans=max(ans,(q[i]+r[i]-1)/r[i]);
	}
	printf("%d\n",ans);
	int idx=0;
	for(int i=k;i>=1;i--){
		while(p[i]>0){
			p[i]--;
			tmp[idx].push_back(i);
			idx++;
			if(idx==ans) idx=0;
		}
	}
	for(int i=0;i<ans;i++){
		printf("%d ",tmp[i].size());
		for(int j=0;j<tmp[i].size();j++) printf("%d ",tmp[i][j]);
		puts("");
	}
}