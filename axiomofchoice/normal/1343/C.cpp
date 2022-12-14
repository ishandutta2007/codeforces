#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf;
//#define int ll
int a[N];
#define sgn(x) ((x)>0?1:-1)
signed main(){
	for(int T=read();T--;){
		int n=read();
		repeat(i,0,n)a[i]=read();
		int flag=sgn(a[0]);
		int m=-inf;
		ll ans=0;
		repeat(i,0,n){
			if(sgn(a[i])==flag){
				m=max(m,a[i]);
			}
			else{
				flag=-flag;
				ans+=m;
				m=a[i];
			}
		}
		ans+=m;
		cout<<ans<<endl;
	}
	return 0;
}