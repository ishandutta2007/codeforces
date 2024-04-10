#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int powdv(int x,int y=mod-2){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
char s[200005];
int f[2][2][2][200005];
void add(int* x,int a){
	(*x)=((*x)+a)%mod;
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	f[0][0][0][n+1]=1;
	for(int i=n;i>=1;--i){
		for(int a=0;a<2;++a)
			for(int b=0;b<2;++b)
				for(int c=0;c<2;++c){
					if(s[i]=='0'){
						add(&f[a][b][c][i],f[a][b][c][i+1]);
						add(&f[1][1][1][i],f[a][b][c][i+1]);
						add(&f[a][b][1][i],f[a][b][c][i+1]);
						add(&f[a][1][1][i],f[a][b][c][i+1]);
						add(&f[1][b][c][i],f[a][b][c][i+1]);
						add(&f[1][1][c][i],f[a][b][c][i+1]);
					}else{
						add(&f[0][0][0][i],f[a][b][c][i+1]);
						add(&f[a][b][c][i],f[a][b][c][i+1]);
						add(&f[0][0][c][i],f[a][b][c][i+1]);
						add(&f[0][b][c][i],f[a][b][c][i+1]);
						add(&f[a][0][0][i],f[a][b][c][i+1]);
						add(&f[a][b][0][i],f[a][b][c][i+1]);
					}
				}
	}
	int gs=f[0][0][0][1];
	int sg=0;
	for(int i=1;i<=n;++i)sg=(sg*2+(s[i]-'0'))%mod;
	int ans=0;
	ans=1ll*(sg+1)*(sg+1)%mod*(sg+1)%mod;
	ans=(ans-3ll*gs)%mod;
	ans=(ans+3ll*(sg+1)*(sg+1)%mod);
	ans=(ans-(sg+1))%mod;
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}