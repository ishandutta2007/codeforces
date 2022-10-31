#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100100
#define Q 1000000007
int ed[N],f[N],cnt=0,dp[N],dp2[N];
char s[N],t[N];
using namespace std;
int main(){
	scanf("%s%s",s,t);
	int i,j,len,slen;
	f[0]=-1;
	for(i=1;t[i];i++){
		for(j=f[i-1];j>=0;j=f[j]){
			if(t[j+1]==t[i]) break;
		}
		if(j>=0) f[i]=j+1;
		else if(t[i]==t[0]) f[i]=0;
		else f[i]=-1;
	}
	len=i;
	j=-1;
	for(i=0;s[i];i++){
		while(j>=0&&s[i]!=t[j+1]) j=f[j];
		if(j>=0) j++;
		else if(s[i]==t[0]) j=0;
		else  j=-1;
		if(j==len-1){
			ed[cnt++]=i+1;
			j=f[j];
		}
	}
	slen=i;
	dp[slen]=1;
	dp2[slen]=1;
	for(i=slen-1;i>=0;i--){
		int *p=lower_bound(ed,ed+cnt,i+len);
		if(p==ed+cnt) dp[i]=0;
		else{
			dp[i]=dp2[*p];
		}
		dp[i]=(dp[i]+dp[i+1])%Q;
		dp2[i]=(dp[i]+dp2[i+1])%Q;
	}
	printf("%d\n",(dp[0]+Q-1)%Q);
	return 0;
}