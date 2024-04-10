#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define N 200020
typedef long long ll;
inline void inc(int &x,int y){
	(x+=y)>=mod?x-=mod:233;
}
char s[N];
int n,dp[N][4][2][2][2];
int dfs(int u,int op,int limx,int limy,int limz){
	if(u>n)return op==3;
	int &ans=dp[u][op][limx][limy][limz];
	if(~ans)return ans;
	ans=0;
	int c=s[u]-'0';
	for(int x=0;x<=(limx?c:1);++x){
		for(int y=0;y<=(limy?c:1);++y){
			for(int z=0;z<=(limz?c:1);++z){
				int t=op;
				if(x+y+z>=1&&x+y+z<=2){
					int a=x^y;
					int b=x^z;
					int c=y^z;
					if(op==0){
						if(a==1&&b==1){
							++t;
						}
						else{
							continue;
						}
					}
					else if(op==1){
						if(a==1&&b==1){
							
						}
						else if(a==1&&c==1){
							++t;
						}
						else{
							continue;
						}
					}
					else if(op==2){
						if(a==1&&b==1){
							
						}
						else if(a==1&&c==1){
							
						}
						else if(b==1&&c==1){
							++t;
						}
						else{
							continue;
						}
					}
				}
				inc(ans,dfs(u+1,t,limx&&x==c,limy&&y==c,limz&&z==c));
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	memset(dp,-1,sizeof(dp));
	cout<<6LL*dfs(1,0,1,1,1)%mod<<'\n';
	return 0;
}