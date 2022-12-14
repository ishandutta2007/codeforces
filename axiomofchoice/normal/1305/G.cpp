#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
typedef long long ll; const int inf=~0u>>2;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=1<<18;
struct DSU{ //d[x]=d[y]d[x]==d[y]
	int a[N];
	void init(int n){iota(a,a+n+1,0);}
	int &operator[](int x){
		return a[x]==x?a[x]:(a[x]=(*this)[a[x]]);
	}
}d;
ll ans=0;
int n,cnt[N],vis[N];
int getcnt(int x){
	if(vis[x])return 1;
	vis[x]=1;
	return cnt[x];
}
int connect(int x,int p){
	x=d[x]; p=d[p]; if(x==p)return 0;
	d[x]=p;
	return getcnt(x)+getcnt(p)-1;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	d.init(N-1);
	repeat(i,0,n){
		int x; cin>>x;
		cnt[x]++;
		ans-=x;
	}
	cnt[0]++;
	repeat_back(s,0,N)
	for(int x=s;x;x=(x-1)&s){
		int p=s^x;
		if(cnt[x] && cnt[p]){
			//cout<<x<<' '<<p<<endl;
			ans+=(ll)s*connect(x,p);
		}
	}
	cout<<ans<<endl;
	return 0;
}