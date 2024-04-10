#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 2010
using namespace std;
int main(){
	char s1[N],s2[N];
	int ans[N]={},fb[N]={},dp[N],tmp[N],gt[N][26],l1,l2,i,j,k;
	scanf("%s%s",s1,s2);
	l1=strlen(s1);
	l2=strlen(s2);
	memset(dp,-1,sizeof(dp));
	memset(tmp,-1,sizeof(tmp));
	for(i=0;i<l2;i++){
		for(j=fb[i];j&&s2[j]!=s2[i];j=fb[j]);
		if(j) fb[i+1]=j+1;
		else if(i&&s2[i]==s2[0]) fb[i+1]=1;
		else fb[i+1]=0;
		for(j=0;j<26;j++){
			for(k=i;k&&'a'+j!=s2[k];k=fb[k]);
			if(s2[k]=='a'+j) gt[i][j]=k+1;
			else gt[i][j]=0;
		}
	}
	dp[0]=0;
	for(i=0;i<l1;i++){
		for(j=0;j<=i;j++){
			if(dp[j]>=0){
				tmp[j]=tmp[j]==-1?dp[j]+1:min(tmp[j],dp[j]+1);
				int nxt=gt[j%l2][s1[i]-'a']+(j/l2)*l2;
				tmp[nxt]=tmp[nxt]==-1?dp[j]:min(dp[j],tmp[nxt]);
			}
		}
		for(j=0;j<=i+1;j++){
			dp[j]=tmp[j];
			tmp[j]=-1;
		}
	}
	for(i=0;i<=l1;i++){
		if(dp[i]>=0){
			for(j=dp[i];j<=l1;j++){
				ans[j]=max(ans[j],(l1-j>i?i:l1-j)/l2);
			}
		}
	}
	for(i=0;i<=l1;i++){
		if(i) putchar(' ');
		printf("%d",ans[i]);
	}
	putchar('\n');
	return 0;
}