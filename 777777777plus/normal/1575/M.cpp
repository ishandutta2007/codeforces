#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e3+5;

int n,m; 
char a[N][N];
vector<int> v[N];
ll ans;

db get(pair<int,int> a,pair<int,int> b){
	if(a.second==b.second){
		return 1.*(a.first+b.first)/2;
	}
	db k=1.*(b.second-a.second)/(b.first-a.first);
	k=-1/k;
	db x1=1.*(a.first+b.first)/2;
	db y1=1.*(a.second+b.second)/2;
	db b1=y1-k*x1;
	return -b1/k;
}

int sqr(int x){
	return x*x;
}

int main(){
	scanf("%d%d",&n,&m);
	++n;
	++m;
	for(int i=1;i<=n;++i){
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;++j)
		if(a[i][j]=='1'){
			v[i].push_back(j);
		}
	}
	static int c[N];
	for(int i=1;i<=n;++i)c[i]=0;
	for(int j=1;j<=m;++j){
		static int b[N];
		for(int i=1;i<=n;++i){
			while(c[i]+1<v[i].size()&&abs(v[i][c[i]+1]-j)<abs(v[i][c[i]]-j)){
				++c[i];
			}
			if(v[i].size())b[i]=abs(v[i][c[i]]-j);
			else b[i]=-1;
		}
		static pair<int,int> q[N];
		int l=1,r=0;
		static int d[N];
		for(int i=1;i<=n;++i)d[i]=2e9;
		for(int i=1;i<=n;++i){
			if(~b[i]){
				while(l<r&&get(q[r-1],q[r])>=get(q[r],make_pair(i,b[i])))--r;
				q[++r]=make_pair(i,b[i]);
			}
			while(l<r&&sqr(q[l].second)+sqr(q[l].first-i)>=sqr(q[l+1].second)+sqr(q[l+1].first-i))++l;
			if(l<=r)d[i]=min(d[i],sqr(q[l].second)+sqr(q[l].first-i));
		}
		l=1,r=0;
		for(int i=n;i>=1;--i){
			if(~b[i]){
				while(l<r&&get(q[r-1],q[r])<=get(q[r],make_pair(i,b[i])))--r;
				q[++r]=make_pair(i,b[i]);
			}
			while(l<r&&sqr(q[l].second)+sqr(q[l].first-i)>=sqr(q[l+1].second)+sqr(q[l+1].first-i))++l;
			if(l<=r)d[i]=min(d[i],sqr(q[l].second)+sqr(q[l].first-i));
		}
		for(int i=1;i<=n;++i)ans+=d[i];
	}
	printf("%lld\n",ans);
}