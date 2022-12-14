#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf;
//#define int ll
signed main(){
	for(int T=read();T--;){
		int n=read();
		if(n%4==2)cout<<"NO"<<endl;
		else{
			ll sum=0;
			cout<<"YES"<<endl;
			repeat(i,1,n/2+1)
				cout<<i*2<<' ',sum+=i*2;
			repeat(i,1,n/2)
				cout<<i*2-1<<' ',sum-=i*2-1;
			cout<<sum<<endl;
		}
	}
	return 0;
}