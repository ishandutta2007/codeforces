#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1E5+5;

int n,k;
vector<int> a[N];
vector<ll> b[N];
ll ans;

void add(vector<ll> &g,vector<ll> f,int l,int r){
	for(int j=1;j<=k;++j)g[j]=f[j]; 
	for(int i=1;i<=r-l+1;++i){
		int cnt=a[i+l-1].size();
		for(int j=k;j>=cnt;--j){
			g[j]=max(g[j],g[j-cnt]+b[i+l-1][cnt]);
		}
	}
}

void Solve(int l,int r,vector<ll> f){
	if(l==r){
		int cnt=min(k,(int)a[l].size());
		for(int t=0;t<=cnt;++t){
			ans=max(ans,f[k-t]+b[l][t]);
		}
		return;
	}
	int mid=l+r>>1;
	vector<ll> g,g1;
	g.resize(k+1);
	g1.resize(k+1);
	add(g,f,mid+1,r);
	Solve(l,mid,g);
	add(g1,f,l,mid);
	Solve(mid+1,r,g1);
}

int main(){
	cin>>n>>k;
	for(int i=1,t,x;i<=n;++i){
		scanf("%d",&t);
		b[i].push_back(0);
		for(int j=1;j<=t;++j){
			scanf("%d",&x);
			a[i].push_back(x);
			b[i].push_back(b[i][b[i].size()-1]+x);
		}
	}
	vector<ll> f;
	f.resize(k+1);
	Solve(1,n,f);
	cout<<ans<<endl;
}