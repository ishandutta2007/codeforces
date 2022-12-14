#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 200010
#define mod 2147483647
#define int ll

pii h[N];
int a0[N],maxs[N];
int n,m;
#define zero 0
struct ST{//build(1,1,n) update(1,1,n,?,?,?) query(1,1,n,?,?)
	ll a[800010];//
	void build(int n,int l,int r){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		if(l==r){
			a[n]=a0[m];
			return;
		}
		build(lc,l,m);
		build(rc,m+1,r);
		a[n]=max(a[lc],a[rc]);
	}
	ll query(int n,int l,int r,int x,int y){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		x=max(x,l); y=min(y,r); if(x>y)return zero;
		if(x==l && y==r)
			return a[n];
		return max(query(lc,l,m,x,y),query(rc,m+1,r,x,y));
	}
}st;

signed main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		repeat(i,0,n)cin>>a0[i];
		st.build(1,0,n-1);
		cin>>m;
		repeat(i,1,m+1)cin>>h[i].first>>h[i].second;
		sort(h+1,h+m+1,greater<pii>());
		maxs[0]=-1;
		repeat(i,1,m+1){
			maxs[i]=max(maxs[i-1],h[i].second);
		}
		int p=0,ans=0;
		while(p<n){//cout<<1<<endl;
			int l=p,r=n-1,mid;
			while(l<=r){
				mid=(l+r)/2;
				int k=st.query(1,0,n-1,p,mid);
				//cout<<mid<<' '<<k<<endl;
				//getchar();
				int pos=upper_bound(h+1,h+m+1,make_pair(k,-1),greater<pii>())-h;
				pos--;
				if(maxs[pos]>=mid-p+1)
					l=mid+1;
				else
					r=mid-1;
			}
			if(p==r+1){ans=-1;break;}
			p=r+1;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}