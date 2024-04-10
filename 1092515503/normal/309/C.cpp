#include<bits/stdc++.h>
using namespace std;
const int LOG=31; 
int n,m,cnt[32],t,mul[32],ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		for(int j=0;j<LOG;j++)if(t&(1<<j))cnt[j]++;
	}
	for(int i=1;i<=m;i++)scanf("%d",&t),mul[t]++;
	for(int i=0;i<LOG;i++){
		while(cnt[i]<mul[i]){
			bool flag=false;
			for(int j=i+1;j<LOG;j++){
				if(!cnt[j])continue;
				for(int k=i+1;k<j;k++)cnt[k]++;
				cnt[j]--,cnt[i]+=2,flag=true;
				break;
			}
			if(!flag)break;
		}
		ans+=min(cnt[i],mul[i]);
	}
	printf("%d\n",ans);
	return 0;
}