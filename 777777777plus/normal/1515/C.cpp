#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,m,x;
int a[N],id[N];
int ans[N];
set<pair<int,int> > w;

bool cmp(int x,int y){
	return a[x]<a[y];
}

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>x;
		for(int i=1;i<=n;++i)cin>>a[i],id[i]=i;
		sort(id+1,id+n+1,cmp);
		w.clear();
		for(int i=1;i<=m;++i)w.insert({0,i});
		for(int i=1;i<=n;++i){
			int x=a[id[i]];
			pair<int,int> p=*w.begin();
			w.erase(p);
			p.first+=x;
			ans[id[i]]=p.second;
			w.insert(p);
		}
		int mn=2e9,mx=0;
		for(auto p:w){
			mn=min(mn,p.first);
			mx=max(mx,p.first);
		}
		if(mx-mn>x)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;++i)printf("%d ",ans[i]);
			printf("\n");
		}
	}
}