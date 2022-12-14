#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=2000010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
void Solve(){
	int n=read();
	repeat(i,0,n){
		repeat(j,0,n)
			printf("%d ",(i==j || (i+1)%n==j?1:0));
		puts("");
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}