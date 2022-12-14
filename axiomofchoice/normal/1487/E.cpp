#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;}
pair<int,int> a[4][N];
int n[4];
vector<int> edge[N];
int vis[N],dcnt;
void Solve(){
	repeat(i,0,4)n[i]=read();
	repeat(i,0,4)
	repeat(j,0,n[i])
		a[i][j]={read(),j};
	repeat(i,0,3){
		int m=read();
		repeat(j,0,n[i+1])edge[j].clear();
		repeat(j,0,m){
			int x=read()-1,y=read()-1;
			edge[y].push_back(x);
		}
		sort(a[i],a[i]+n[i]);
		repeat(j,0,n[i+1]){
			dcnt++;
			for(auto k:edge[j])vis[k]=dcnt;
			int ans=5e8;
			repeat(k,0,n[i])
			if(vis[a[i][k].second]!=dcnt){
				ans=a[i][k].first;
				break;
			}
			a[i+1][j].first+=ans;
		}
	}
	int ans=min_element(a[3],a[3]+n[3])->first;
	if(ans>=(int)5e8)ans=-1;
	printf("%d\n",ans);
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; // T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}