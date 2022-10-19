#include<bits/stdc++.h>
#define ll long long
#define N 2005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m,a[N],b[N],c[N],d[N],Max[N*N];
struct node{
	int x,y;
	bool operator<(const node&o) const{
		return y<o.y; 
	}
	bool operator==(const node&o) const{
		return o.x==x&&o.y==y;
	}
};
vector<node> v;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>n>>m;
 	rep(i,1,n) cin>>a[i]>>b[i];
 	rep(i,1,m) cin>>c[i]>>d[i];
 	int ans = inf,ma,mb; ma = mb = 0;
 	rep(i,1,n){
 		rep(j,1,m){
 			if(c[j] >= a[i]&&d[j] >= b[i]) ma = max(ma,c[j]-a[i]+1),mb = max(mb,d[j]-b[i]+1),v.pb(node{c[j]-a[i]+1,d[j]-b[i]+1});
 		}
 	}
 	ans = min({ans,ma,mb});
 	sort(v.begin(),v.end());
 	int sz = unique(v.begin(),v.end())-v.begin();
 	//int sz = v.size();
 	//if(sz==0) ans = 0;
 	//rep(i,0,sz-1) cout << v[i].x << '#' << v[i].y << endl;
 	//ans = min({ans,v[0].y,v[sz-1].x});
 	per(i,0,sz-1) Max[i] = max(Max[i+1],v[i].x);
 	rep(i,1,sz-1){
 		ans = min(ans,v[i-1].y+Max[i]);
 	}
 	//cout << m1 << ' ' << m2 << endl;
 	cout << ans;
	return 0;
}