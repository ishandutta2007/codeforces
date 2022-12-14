#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=510; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;}
char s[N][N];
void Solve(){
	int n=read(),m=read();
	int p=0; if(n%3==0)p=1;
	repeat(i,0,n){
		scanf("%s",s[i]);
	}
	for(int i=p;i<n;i+=3){
		repeat(j,0,m)s[i][j]='X';
	}
	for(int i=p;i+3<n;i+=3){
		int f=0;
		repeat(j,0,m){
			if(s[i+1][j]=='X' || s[i+2][j]=='X'){
				s[i+1][j]=s[i+2][j]='X'; f=1;
				break;
			}
		}
		if(f==0)s[i+1][0]=s[i+2][0]='X';
	}
	repeat(i,0,n)puts(s[i]);
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}