#include<bits/stdc++.h>
using namespace std;
int dp[1<<24];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char s[10];
		scanf("%s",s);
		for(int j=1;j<8;j++){
			int sgn=-1,st=0;
			for(int k=0;k<3;k++){
				if(j&(1<<k)){
					sgn=-sgn;
					st|=(1<<s[k]-'a');
				}					
			}
			dp[st]+=sgn;
		}
	}
	for(int i=0;i<24;i++){
		for(int j=0;j<(1<<24);j++){
			if(j&(1<<i)) dp[j]+=dp[j^(1<<i)];
		}
	}
	int ans=0;
	for(int i=0;i<(1<<24);i++){
		ans^=dp[i]*dp[i];
	}
	printf("%d\n",ans);
	return 0;
}