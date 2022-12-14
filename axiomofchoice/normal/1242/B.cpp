#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 100010
#define mod 2147483647
#define int ll
int n,m,du[N],ans=0,u,v;
set<int> s;
set<pii> Set;
map<int,int> Map;
mt19937 rnd(time(0));
bool f[N];
set<int> a[N];
vector<pair<int,pii> > e;
int LINK[500][500];
void work(int i){
	if(f[i])return;
	vector<int> t;
	for(auto k:s){
		if(!a[i].count(k)){
			t.push_back(k);
		}
	}
	for(auto k:t){
		f[k]=0;
		s.erase(k);
	}
	for(auto k:t){
		work(k);
	}
}
struct DSU{//d[x]=d[y]d[x]==d[y]
	int a[100010];
	void init(){
		repeat(i,0,n+1)a[i]=i;
	}
	int fa(int x){
		return a[x]==x?x:a[x]=fa(a[x]);
	}
	int& operator[](int x){
		return a[fa(x)];
	}
}D;

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	repeat(i,0,m){
		cin>>u>>v;u--,v--;
		du[u]++;
		du[v]++;
		a[u].insert(v);
		a[v].insert(u);
		Set.insert({u,v});
		//Set.insert({v,u});
	}
	int mi=0;
	repeat(i,0,n){
		if(du[i]==0){cout<<0<<endl;return 0;}
		if(du[i]<du[mi])mi=i;
	}
	for(auto i:a[mi]){
		f[i]=1;
	}
	s=a[mi];
	repeat(i,0,n)work(i);
	
	if(s.size()<=1){cout<<s.size()<<endl;return 0;}
	
	int cnt=0;
	repeat(i,0,n)
		if(f[i])Map[i*2]=cnt++;
	for(auto i:Set){
		if(f[i.first] && f[i.second]){
			u=Map[i.first*2];
			v=Map[i.second*2];
			LINK[u][v]=1;
			LINK[v][u]=1;
		}
	}
	D.init();
	repeat(i,0,cnt)
	repeat(j,i+1,cnt)
		e.push_back(make_pair(LINK[i][j],(pii){i,j}));
	//repeat(i,0,cnt)
	//repeat(j,0,cnt)
		//cout<<LINK[i][j]<<" \n"[j==cnt-1];
	sort(e.begin(),e.end());
	for(auto i:e){
		if(D[i.second.first]!=D[i.second.second]){
			ans+=i.first;
			D[i.second.first]=D[i.second.second];
		}
	}
	cout<<ans+1<<endl;
	return 0;
}