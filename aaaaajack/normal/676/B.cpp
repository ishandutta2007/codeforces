#include<bits/stdc++.h>
using namespace std;
int cap[20][20],spd[20][20];
int main(){
	int ans=0,n,t;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cap[i][j]=1<<n;
		}
	}
	cap[0][0]-=(t<<n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(cap[i][j]<=0){
				ans++;
				cap[i+1][j]+=cap[i][j]>>1;
				cap[i+1][j+1]+=cap[i][j]>>1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}