#include<bits/stdc++.h>
using namespace std;
char s[55];
int mx,mc,i,l,f[55][55][555][2];
int dp(int p,int c,int x,int d){
	if(p==l)return c?1e9:0;
	if(abs(c)>mc||abs(x)>mx)return 1e9;
	if(~f[p][c+mc][x+mx][d])return f[p][c+mc][x+mx][d];
	return f[p][c+mc][x+mx][d]=min(dp(p,c,x+(d?1:-1),d)+l-p,min(dp(p+1,c*10+s[p+1]-x,x,0),dp(p+1,c*10+s[p+1]-x,x,1)));
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	cin>>(s+2),l=strlen(s+2)+1,mx=l*5,mc=mx/10+1,memset(f,-1,sizeof f);
	for(i=2;i<=l;++i)s[i]-=48;
	cout<<dp(0,0,0,1);
	return 0;
}