#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;}
int a[N];
void Solve(){
	int n=read(),k=read();
	if(n%2==0)
		printf("%d\n",(k-1)%n+1);
	else{
		int T=n/2;
		int delta=(k-1)%T*2+1;
		int pos=n-(k-1)%n;
		printf("%d\n",(pos+delta-1)%n+1);
	}
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}