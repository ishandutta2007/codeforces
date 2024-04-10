//by dxm
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

int n,x[1005],y[1005];
int cnt[2][2];
int main(){
	int n;scanf("%d",&n);rep(i,n)scanf("%d%d",&x[i],&y[i]);
	rep(i,n){x[i]+=1000000;y[i]+=1000000;}
	while(true){
		rep(i,2)rep(j,2)cnt[i][j]=0;
		rep(i,n)cnt[x[i]&1][y[i]&1]++;
		int tot=0;rep(i,2)rep(j,2)if(cnt[i][j]!=0)tot++;
		if(tot>=2){
			vector<int>ans;
			if((cnt[0][0]||cnt[1][1])&&(cnt[0][1]||cnt[1][0])){
				rep(i,n)if((x[i]^y[i])&1)ans.push_back(i+1);
				printf("%d\n",(int)ans.size());rep(i,ans.size())printf("%d ",ans[i]);
				return 0;
			}else if(cnt[0][0]){
				rep(i,n)if(x[i]&1)ans.push_back(i+1);
				printf("%d\n",(int)ans.size());rep(i,ans.size())printf("%d ",ans[i]);
				return 0;
			}else if(cnt[1][0]){
				rep(i,n)if(x[i]&1)ans.push_back(i+1);
				printf("%d\n",(int)ans.size());rep(i,ans.size())printf("%d ",ans[i]);
				return 0;
			}
		}
		rep(i,n){x[i]/=2;y[i]/=2;}
	}
	return 0;
}