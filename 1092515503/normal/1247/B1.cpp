#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,num[110],cnt[110],mn,tot;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k),mn=0x3f3f3f3f;
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		for(int i=1;i+k-1<=n;i++){
			memset(cnt,0,sizeof(cnt)),tot=0;
			for(int j=i;j<=i+k-1;j++){
				tot+=!cnt[num[j]];
				cnt[num[j]]++;
			}
			mn=min(mn,tot);
		}
		printf("%d\n",mn);
	}
	return 0;
}