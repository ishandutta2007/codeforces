#include<bits/stdc++.h>
using namespace std;
int s[1000005],d[1000005],tot=0;
void print(){
	s[1]=1;
	for(int i=2;i<=1000000;++i){
		if(!s[i])d[++tot]=i;
		for(int j=1;j<=tot&&i*d[j]<=1000000;++j){
			s[i*d[j]]=1;
			if(i%d[j]==0)break;
		}
	}
}
int a[100005];
struct apple{
	int a,wz;
	bool operator<(const apple &other)const{
		return a<other.a;
	}
}e[100005];
int v(int p,int x){
	int gs=0;
	while(x%p==0)x/=p,++gs;
	return gs;
}
auto xdg(auto g){
	if(!g.size())return g;
	int n=g.size();
	int x=g[0];
	vector<int>ans;
	for(int i=1;i<=tot;++i)if(x%d[i]==0){
		int mm=v(d[i],x);
		for(auto cu:ans)mm=min(mm,v(d[i],cu));
		int mn=v(d[i],x),w=0;
		for(int j=1;j<n;++j){
			int vv=v(d[i],g[j]);
			if(mn>vv)mn=vv,w=j;
		}
		if(mn<mm){
			ans.emplace_back(g[w]);
		}
	}
	if(ans.size()!=7)ans.emplace_back(x);
	return ans;
}
int vist[1000005];
int main(){
	print();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),++vist[a[i]];
	vector<int>g;
	for(int i=1;i<=1000000;++i)for(int j=1;j<=vist[i];++j)
		g.emplace_back(i);
	auto gg=xdg(g);
	for(auto cu:gg)--vist[cu];
	g.clear();
	for(int i=1;i<=1000000;++i)for(int j=1;j<=vist[i];++j)
		g.emplace_back(i);
	auto ggg=xdg(g);
	for(int i=1;i<=n;++i)e[i].a=a[i],e[i].wz=i;
	sort(e+1,e+n+1);
	vector<int>v;
	for(auto cu:gg)v.emplace_back(cu);
	for(auto cu:ggg)v.emplace_back(cu);
	sort(v.begin(),v.end());
	int m=v.size();
	int dj[105];
	int wz=1;
	for(int i=0;i<m;++i){
		while(wz<=n&&(v[i]>e[wz].a||!e[wz].wz))++wz;
		dj[i]=e[wz].wz,e[wz].wz=0;
	}
	vector<pair<int,vector<int>>>ans;
	for(int i=1;i<(1<<m);++i){
		int bp=__builtin_popcount(i);
		int cs=(bp-2)*(bp%2==1?-1:1);
		if(cs>0){
			vector<int>qz;
			for(int j=0;j<m;++j)if(i&(1<<j))qz.emplace_back(dj[j]);
			sort(qz.begin(),qz.end());
			auto as=make_pair(0,qz);
			while(cs--){
				ans.emplace_back(as);
			}
		}else if(cs<0){
			vector<int>qz;
			for(int j=0;j<m;++j)if(i&(1<<j))qz.emplace_back(dj[j]);
			sort(qz.begin(),qz.end());
			auto as=make_pair(1,qz);
			while(cs++){
				ans.emplace_back(as);
			}
		}
	}
	printf("%d\n",(signed)ans.size());
	for(auto pi:ans){
		printf("%d ",pi.first);
		auto as=pi.second;
		printf("%d",(signed)as.size());
		for(auto cu:as)printf(" %d",cu);
		printf("\n");
	}
	return 0;
}