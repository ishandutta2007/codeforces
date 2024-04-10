#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll; const int inf=2e9;
typedef double lf; const lf err=1e-11; typedef long double llf;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define fi first
#define se second
ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
mt19937 rnd(time(0));
#define writearr(a,n) cerr<<#a": "; repeat(I,0,n)cerr<<(a)[I]<<" \n"[I==n-1];
const int N=100010;
const int mod=(1?1000000007:998244353);
//#define int ll
signed main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		if(n>=3 && n%2==1)
			cout<<7,n-=3;
		repeat(i,0,n/2)cout<<1;
		cout<<endl;
	}
	return 0;
}