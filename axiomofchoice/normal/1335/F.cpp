#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#ifdef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
const int N=1000010; typedef long long ll; const int inf=~0u>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
typedef pair<int,int> pii;
map<int,pii> dir={{'L',{0,-1}},{'R',{0,1}},{'U',{-1,0}},{'D',{1,0}}};
int n,m;
vector<int> a[N];
inline int f(int x,int y){return x*m+y;}
int vis[N];
bool val[N];
int to[N],co[N],start[N],len[N],dis[N];
string s;
int dcnt,cocnt,ans1,ans2;
#define orzz(a) []{cout<<"*****"#a"*****:"<<endl;repeat(i,0,n)repeat(j,0,m)cout<<a[f(i,j)]<<" \n"[j==m-1];}()
void work1(int x0){
	int x=x0;
	dcnt++;
	//orz(x0);
	while(vis[x]==0){
		vis[x]=dcnt;
		x=to[x];
	}
	if(vis[x]==dcnt){//qwq;
		cocnt++; len[cocnt]=0;
		while(co[x]==0){
			len[cocnt]++;
			ans1++;
			co[x]=cocnt;
			x=to[x];
		}
		start[x]=1;
	}
	//orzz(vis);
}
queue<int> q;
bool bkt[N];
void work2(int x0){
	dis[x0]=1;
	q.push(x0);
	int nowco=co[x0];
	int nowlen=len[nowco];
	//orz(x0);orz(nowlen);
	fill(bkt,bkt+nowlen,0);
	while(!q.empty()){
		int x=q.front(); q.pop();
		if(val[x] && bkt[dis[x]%nowlen]==0){
			ans2++;
			bkt[dis[x]%nowlen]=1;
		}
		for(auto p:a[x]){
			if(dis[p]==0){
				dis[p]=dis[x]+1;
				q.push(p);
			}
		}
	}
}
signed main(){
	int T; cin>>T;
	while(T--){
		cin>>n>>m; cocnt=dcnt=0; ans1=ans2=0;
		fill(vis,vis+n*m,0);
		fill(co,co+n*m,0);
		fill(dis,dis+n*m,0);
		fill(start,start+n*m,0);
		repeat(i,0,n){
			cin>>s;
			repeat(j,0,m)val[f(i,j)]=(s[j]!='1');
		}
		repeat(i,0,n){
			cin>>s;
			repeat(j,0,m)
				to[f(i,j)]=f(i+dir[s[j]].first,j+dir[s[j]].second);
		}
		//orzz(val);
		//orzz(to);
		repeat(i,0,n*m)if(vis[i]==0)work1(i);
		//orzz(vis);
		//orzz(len);
		//orzz(start);
		//break;
		repeat(i,0,n*m)a[i].clear();
		repeat(i,0,n*m)a[to[i]].push_back(i);
		repeat(i,0,n*m)if(start[i])work2(i);
		cout<<ans1<<' '<<ans2<<endl;
	}
	return 0;
}