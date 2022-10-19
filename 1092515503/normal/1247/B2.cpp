#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,num[2100000],cnt[2100000],mn,tot;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k),mn=0x3f3f3f3f,tot=0;
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		for(int i=1;i<=n;i++){
			if(i>k)cnt[num[i-k]]--,tot-=!cnt[num[i-k]];
			tot+=!cnt[num[i]];
			cnt[num[i]]++;
			if(i>=k)mn=min(mn,tot);
		}
		for(int i=n-k+1;i<=n;i++)cnt[num[i]]--;
		printf("%d\n",mn);
	}
	return 0;
}