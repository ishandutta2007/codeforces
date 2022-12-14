#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll; const int inf=2e9;
typedef double lf; const lf err=1e-7;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define Clear(a) {a=decltype(a)();}
#define qwq {cerr<<"qwq"<<endl;}
#define orz(x) {cerr<<#x": "<<x<<endl;}
ll read(){ll n; scanf("%lld",&n); return n;}
const int N=10010;
const int mod=1e9+7;
#define int ll
int n,s,k;
set<int> S;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n>>s>>k;
		S.clear();
		repeat(i,0,k){
			int x; cin>>x;
			S.insert(x);
		}
		int p=s,ans=inf;
		while(S.count(p))p++;
		if(p<=n)ans=min(ans,p-s);
		p=s;
		while(S.count(p))p--;
		if(p>=1)ans=min(ans,s-p);
		cout<<ans<<endl;
	}
	return 0;
}