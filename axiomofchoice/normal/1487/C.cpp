#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=110; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;}
int a[N][N];
void Solve(){
	int n=read();
	repeat(i,1,n+1)repeat(j,1,n+1)a[i][j]=0;
	for(int i=2;n-i+2>i;i++){
		repeat(j,1,n+1){
			a[j][(i+j-2)%n+1]=1;
			a[(i+j-2)%n+1][j]=-1;
		}
	}
	repeat(i,1,n+1)
	repeat(j,i+1,n+1)
		printf("%d ",a[i][j]);
	puts("");
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}