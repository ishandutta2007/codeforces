#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct DSU{
	vector<int> bo,ss;
	void init(int n){
		bo.resize(n);
		ss.resize(n,1);
		iota(bo.begin(),bo.end(),0);
	}
	int find(int x){
		return bo[x]==x?x:bo[x]=find(bo[x]);
	}
	int merge(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y){
			return 0;
		}
		if(ss[x]>ss[y]){
			swap(x,y);
		}
		bo[x]=y;
		ss[y]+=ss[x];
		return 1;
	}
}d1,d2;
vector<set<int> > e;
set<int> s;
long long rem=0,ans=0;
void dfs(int x){
	s.erase(x);
	for(int i=0;;){
		auto h=s.lower_bound(i);
		if(h==s.end()){
			break;
		}
		i=*h;
		if(e[x].find(i)==e[x].end()){
			d1.merge(x,i);
			dfs(i);
			rem--;
		}
		i++;
	}
}
int main(){
    AquA;
	int n,m;
	cin >> n >> m;
	int nw=0;
	rem=1ll*n*(n-1)/2-m;
	d1.init(n);
	d2.init(n);
	for(int i=0;i<n;i++){
		s.insert(i);
	}
	e.resize(n);
	vector<pair<int,pair<int,int>>> eg;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		e[a].insert(b);
		e[b].insert(a);
		eg.push_back({c,{a,b}});
		nw^=c;
	}
	for(int i=0;i<n;i++){
		if(s.find(i)!=s.end()){
			dfs(i);
		}
	}
	if(rem){
		nw=0;
	}
	sort(eg.begin(),eg.end());
	for(auto h:eg){
		if(d1.merge(h.sc.fs,h.sc.sc)){
			d2.merge(h.sc.fs,h.sc.sc);
			ans+=h.fs;
		}
		else if(d2.merge(h.sc.fs,h.sc.sc)){
			nw=min(nw,h.fs);
		}
	}
	cout << ans+nw << "\n";
	return 0;
}