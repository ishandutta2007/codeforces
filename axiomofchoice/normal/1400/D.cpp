#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=3010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
vector<int> a[N];
ll ans;
void work(const vector<int> &a,const vector<int> &b){
	repeat(i,0,a.size()){
		int p1=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		repeat(j,i+1,a.size()){
			int p2=lower_bound(b.begin(),b.end(),a[j])-b.begin();
//			if((p2-p1)*p1+(p2-p1)*(b.size()-p2)>0){
//				orzeach(a);
//				orzeach(b);
//				orz(make_pair(p1,p2));
//			}
			ans+=(p2-p1)*p1+(p2-p1)*(b.size()-p2);
		}
	}
}
void Solve(){
	int n=read(); ans=0;
	repeat(i,1,n+1)a[i].clear();
	repeat(i,1,n+1){
		int t=read();
		a[t].push_back(i);
	}
	sort(a+1,a+n+1,[](const vector<int> &a,const vector<int> &b){
		return a.size()<b.size();
	});
	repeat(i,1,n+1)sort(a[i].begin(),a[i].end());
	repeat(i,1,n+1){
		repeat(j,i+1,n+1)
			work(a[i],a[j]);
		if(a[i].size()>=4){
			int n=a[i].size();
			ans+=n*(n-1)*(n-2)*(n-3)/(2*3*4);
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	while(T--)Solve();
	return 0;
}