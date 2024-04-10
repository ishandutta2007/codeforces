#include<bits/stdc++.h>
#define N 300100
using namespace std;
int a[N];
long long b[N];
long long sp[2][N][20];
map<long long,vector<int>> id;
void build(int n){
	for(int p=0;p<2;p++){
		for(int i=1;i<20;i++){
			for(int j=p;j+(1<<i)<=n;j+=2){
				sp[p][j][i]=min(sp[p][j][i-1],sp[p][j+(1<<i)][i-1]);
			}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		id.clear();
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) sp[i&1][i][0]=b[i]=a[i]-b[i-1];
		for(int i=0;i<=n;i++){
			if(i&1) id[-b[i]].push_back(i);
			else id[b[i]].push_back(i);
		}
		long long ans=0;
		build(n);
		for(int i=1;i<=n;i++){
			int rb=i;
			long long pre=b[i-1];
			for(int s=19;s>=0;s--){
				while(rb+(1<<s+1)<=n+1 && sp[i&1][rb][s]>=-pre && sp[(i&1)^1][rb+1][s]>=pre){
					rb+=1<<s+1;
				}
			}
			if(rb<=n && b[rb]>=-pre) rb++;
			vector<int> &v=(i&1)?id[pre]:id[-pre];
			//printf("%d %d v.size=%d\n",i,rb,(int)v.size());
			ans+=lower_bound(v.begin(),v.end(),rb)-lower_bound(v.begin(),v.end(),i);
			//printf("ans=%lld\n",ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}