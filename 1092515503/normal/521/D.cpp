#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,tp[100100];
ll a[100100];
vector<pair<int,int> >u[100100],v[100100];
vector<pair<double,int> >w;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z),tp[i]=x;
		if(x==1)u[y].emplace_back(z,i);
		if(x==2)v[y].emplace_back(z,i);
		if(x==3)w.emplace_back(z,i);
	}
	for(int i=1;i<=n;i++){
		sort(u[i].begin(),u[i].end());
		if(!u[i].empty()&&u[i].back().first>a[i])
			v[i].emplace_back(u[i].back().first-a[i],u[i].back().second);
		sort(v[i].rbegin(),v[i].rend());
		for(auto x:v[i]){
			w.emplace_back(1.0*(a[i]+x.first)/a[i],x.second);
			a[i]+=x.first;
		}
	}
	sort(w.rbegin(),w.rend());
	int lim=min(q,(int)w.size());
	printf("%d\n",lim);
	for(int i=0;i<lim;i++)if(tp[w[i].second]==1)printf("%d ",w[i].second);
	for(int i=0;i<lim;i++)if(tp[w[i].second]==2)printf("%d ",w[i].second);
	for(int i=0;i<lim;i++)if(tp[w[i].second]==3)printf("%d ",w[i].second);
	return 0;
}