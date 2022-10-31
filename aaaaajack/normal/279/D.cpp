#include<bits/stdc++.h>
using namespace std;
char now[1<<25],can[1<<25],num[1<<25];
int a[25];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<(1<<n+1);i++){
		num[i]=num[i^(i&-i)]+1;
	}
	memset(now,127,sizeof(now));
	now[2]=1;
	now[3]=2;
	for(int i=2;i<=n;i++){
		memset(can,0,1<<i);
		for(int j=0;j<i;j++){
			for(int k=0;k<=j;k++){
				if(a[k]+a[j]==a[i]) can[1<<k|1<<j]=1;
			}
		}
		for(int j=0;j<(1<<i);j++){
			for(int k=0;k<i;k++){
				can[j|(1<<k)]|=can[j];
			}
		}
		for(int j=0;j<(1<<i);j++){
			if(can[j]){
				now[j|(1<<i)]=min(now[j|(1<<i)],max(now[j],(char)(num[j]+1)));
				for(int k=j;k>0;k-=k&-k){
					now[(j^(k&-k))|(1<<i)]=min(now[(j^(k&-k))|(1<<i)],now[j]);
				}
			}
			now[j]=127;
		}
	}
	char ans=127;
	for(int i=0;i<(1<<n);i++){
		ans=min(ans,now[i|(1<<n)]);
	}
	if(ans<127) printf("%d\n",(int)ans);
	else puts("-1");
	return 0;
}