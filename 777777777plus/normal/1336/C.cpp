#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N = 3e3+5;
const int mod = 998244353;

int n,m;
int f[N][N];
char s[N],t[N];
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1;i<=n;++i)if(i>m||t[i]==s[1])f[i][i]=2;
	for(int len=1;len<n;++len){
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			if(!f[i][j])continue;
			if(i>1&&(i-1>m||s[len+1]==t[i-1]))(f[i-1][j]+=f[i][j])%=mod;
			if(j<n&&(j+1>m||s[len+1]==t[j+1]))(f[i][j+1]+=f[i][j])%=mod;
		}
	}
	int ans=0;
	for(int i=m;i<=n;++i)
	(ans+=f[1][i])%=mod;
	printf("%d\n",ans);
}