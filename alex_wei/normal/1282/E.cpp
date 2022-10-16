#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

struct chain{
	int ed,to[N];
	void init(int x,int y,int z){
		memset(to,0,sizeof(to));
		to[x]=y,to[y]=ed=z;
	}
	void add(int x,int y,int z){
		if(to[y]==x)swap(x,y);
		else if(to[x]!=y){
			to[ed]=z,ed=z;
			return;
		} to[x]=z,to[z]=y;
	}
	void print(int n){
		int beg; map <int,bool> mp;
		for(int i=1;i<=n;i++)mp[to[i]]=1;
		for(int i=1;i<=n;i++)if(!mp[i]){beg=i; break;}
		while(beg)cout<<beg<<" ",beg=to[beg];
		cout<<endl;
	}
}node;
int n,a[N],b[N],c[N],del[N],pd[N];
set <int> id[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)id[i].clear(),pd[i]=0;
	for(int i=1;i<=n-2;i++){
		cin>>a[i]>>b[i]>>c[i];
		id[a[i]].insert(i),id[b[i]].insert(i),id[c[i]].insert(i);
	} set <int> s; 
	for(int i=1;i<=n;i++)
		if(id[i].size()==1)
			s.insert(i);
	int cnt=1;
	while(cnt<n-2){
		int v=*s.begin(),d=*id[v].begin();
		s.erase(s.begin());
		del[cnt++]=d,pd[d]=1;
		if(b[d]==v)swap(a[d],b[d]);
		if(c[d]==v)swap(a[d],c[d]);
		id[a[d]].erase(id[a[d]].find(d));
		id[b[d]].erase(id[b[d]].find(d));
		id[c[d]].erase(id[c[d]].find(d));
		if(id[b[d]].size()==1)s.insert(b[d]);
		if(id[c[d]].size()==1)s.insert(c[d]);
	} int ed;
	for(int i=1;i<=n-2;i++)
		if(!pd[i]){
			node.init(a[i],b[i],c[i]);
			ed=i; break; 
		}
	for(int i=cnt-1;i>=1;i--)node.add(b[del[i]],c[del[i]],a[del[i]]);
	node.print(n);
	for(int i=1;i<cnt;i++)cout<<del[i]<<" ";
	cout<<ed<<endl;
}

int main(){
	int t; cin>>t;
	while(t--)solve();
}