/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int n,m,bin[4001000],res,dsu[4010],sum[4010],num[4010],sz[4010],val[4010];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){x=find(x),y=find(y);if(x!=y)dsu[x]=y;}
char s[2010][2010];
int main(){
	scanf("%d%d",&n,&m);
	bin[0]=1;for(int i=1;i<=n*m;i++)bin[i]=(bin[i-1]<<1)%mod;
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	if(!(n&1)&&!(m&1)){
		int cnt=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cnt+=(s[i][j]=='?');
		printf("%d\n",bin[cnt]);return 0;
	}
	if(!(m&1)){
		for(int i=1;i<=max(n,m);i++)for(int j=i+1;j<=max(n,m);j++)swap(s[i][j],s[j][i]);
		swap(n,m);
	}
	if(!(n&1)){
		for(int x=0;x<2;x++){
			int pro=1;
			for(int i=1;i<=n;i++){
				int num=0,sum=0;
				for(int j=1;j<=m;j++){
					if(s[i][j]=='?')num++;
					else sum^=(s[i][j]-'0');
				}
				if(num)pro=1ll*pro*bin[num-1]%mod;
				else if(sum!=x)pro=0;
			}
			(res+=pro)%=mod;
		}
		printf("%d\n",res);return 0;
	}
	for(int i=1;i<=n+m;i++)dsu[i]=i;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(s[i][j]=='?')merge(i,n+j);
		if(s[i][j]=='1')sum[i]^=1,sum[n+j]^=1;
	}
	// for(int i=1;i<=n+m;i++)printf("%d ",sum[i]);puts("");
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='?')num[find(i)]++;
	for(int i=1;i<=n+m;i++)sz[find(i)]++,val[find(i)]^=sum[i];
	for(int x=0;x<2;x++){
		int pro=1;
		for(int i=1;i<=n+m;i++)if(dsu[i]==i){
			if(val[i]!=x&&(sz[i]&1)){pro=0;continue;}
			if(val[i]&&!(sz[i]&1)){pro=0;continue;}
			pro=1ll*pro*bin[num[i]-sz[i]+1]%mod;
		}
		(res+=pro)%=mod;
	}
	printf("%d\n",res);
	return 0;
}