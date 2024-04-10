#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=100010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
int t,a[N],n,m,x,f[N];
#define lb(x) (x&(-x))
struct BIT{
	ll t[500010]; //
	void init(){
		mst(t,0);
	}
	void add(ll x,ll k){ //xk
		//x++;
		for(;x<=n;x+=lb(x))
			t[x]+=k;
	}
	ll sum(ll x){ //[1,x] //[0,x]
		//x++;
		ll ans=0;
		for(;x!=0;x-=lb(x))
			ans+=t[x];
		return ans;
	}
}bit;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		fill(bit.t,bit.t+n+1,0);
		repeat(i,0,n)bit.add(i+1,1);
		repeat(i,0,n)
			cin>>x,f[x]=i+1;
		int mx=-1,ans=0;
		repeat(i,0,m){
			cin>>x; x=f[x];
			bit.add(x,-1);
			//cout<<bit.sum(x)<<endl;
			if(mx>x)ans+=1;
			else ans+=bit.sum(x)*2+1;
			mx=max(mx,x);
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}