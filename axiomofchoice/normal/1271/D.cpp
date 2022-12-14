#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=5010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
int n,m,k;
int a[N],b[N],c[N],r[N],f[N];
#define lb(x) (x&(-x))
struct BIT{
	ll t[50010]; //
	void init(){
		mst(t,0);
	}
	void add(ll x,ll k){ //xk
		x++;
		for(;x<=N;x+=lb(x))
			t[x]+=k;
	}
	ll sum(ll x){ //[1,x] //[0,x]
		x++;
		ll ans=0;
		for(;x!=0;x-=lb(x))
			ans+=t[x];
		return ans;
	}
}bit;
priority_queue< tuple<int,int,int> > q;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	repeat(i,0,n)cin>>a[i]>>b[i]>>c[i],r[i]=i;
	f[0]=k-a[0];
	repeat(i,1,n)
		f[i]=f[i-1]+a[i-1]+b[i-1]-a[i];
	
	f[n]=f[n-1]+a[n-1]+b[n-1];
	repeat(i,0,m){
		int x,y; cin>>y>>x; x--,y--;
		r[x]=max(r[x],y);
	}
	repeat(i,0,n)
	if(c[i]>0)
		q.push(make_tuple(c[i],r[i],i));
	repeat_back(i,0,n)
		f[i]=min(f[i],f[i+1]);
	
	if(f[0]<0){cout<<-1<<endl; exit(0);}
	
	repeat(i,0,n)f[i]=f[i+1];
	//repeat(i,0,n)cerr<<f[i]<<' ';cerr<<endl;
	repeat(i,0,n){
		bit.add(i,f[i]);
		bit.add(i+1,-f[i]);
	}
	int ans=0;
	while(!q.empty()){
		int x=get<2>(q.top()); q.pop();
		int l=0,rr=n-1,m;
		int su=bit.sum(r[x]);
		if(su<=0)continue;
		while(l<=rr){
			m=(l+rr)/2;
			if(bit.sum(m)<su)l=m+1;
			else rr=m-1;
		}
		bit.add(l,-1);
		ans+=c[x];
	}
	cout<<ans<<endl;
    return 0;
}