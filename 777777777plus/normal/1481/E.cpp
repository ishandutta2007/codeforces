#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int n;
int a[N],f[N],id[N];
vector<int> g[N];
multiset<int> s;

bool cmp(int x,int y){
	return g[x][0]<g[y][0];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		g[a[i]].push_back(i);
		id[i]=a[i];
	}
	sort(id+1,id+n+1);
	int m=unique(id+1,id+n+1)-id-1;
	sort(id+1,id+m+1,cmp);
	int r=0;
	s.insert(0);
	for(int i=1;i<=m;++i){
		int x=id[i];
		while(r+1<g[x][0]){
			++r;
			s.insert(f[r]);
		}
		int ed=g[x][g[x].size()-1];
		f[ed]=*s.rbegin()+g[x].size();
	}
	for(int i=1;i<=n;++i)f[i]=max(f[i],f[i-1]);
	int ans=0;
	for(int i=1;i<=m;++i){
		int x=id[i];
		for(int j=0;j<g[x].size();++j){
			int p=g[x][j];
			ans=max(ans,f[p-1]+(int)g[x].size()-j);
		}
	}
	printf("%d\n",n-ans);
}