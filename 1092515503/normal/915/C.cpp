#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,occ[10],len1,len2,t,num[20],ans[20],tmp[20];
signed main(){
	scanf("%I64d%I64d",&a,&b);
	t=a;
	while(t)occ[t%10]++,t/=10,len1++;
	t=b;
	while(t)num[++len2]=t%10,t/=10;
	if(len1<len2){
		for(int i=9;i>=0;i--)for(int j=1;j<=occ[i];j++)printf("%I64d",i);
		puts("");
		return 0;
	}
	bool lim=true;
//	printf("%d %d\n",len1,len2);
//	for(int i=0;i<=9;i++)printf("%d",occ[i]);puts("");
	for(int i=len1;i;i--){
		if(occ[num[i]]){
			occ[num[i]]--;
			t=0;
			for(int j=9;j>=0;j--)for(int k=1;k<=occ[j];k++)tmp[++t]=j;
//			printf("%d:\n",i);
//			for(int j=t;j;j--)printf("%d",tmp[j]);puts("");
			bool flag=true;
			for(int j=i-1;j;j--){
				if(tmp[j]==num[j])continue;
				if(tmp[j]>num[j])flag=false;
				break;
			}
			if(flag){
				ans[i]=num[i];
				continue;
			}
			occ[num[i]]++;
		}
		int pos=num[i]-1;
		while(!occ[pos])pos--;
		ans[i]=pos;
		occ[pos]--;
		t=0;
		for(int j=0;j<=9;j++)for(int k=1;k<=occ[j];k++)ans[++t]=j;
		break;
	}
	for(int i=len1;i;i--)printf("%I64d",ans[i]);
	return 0;
}