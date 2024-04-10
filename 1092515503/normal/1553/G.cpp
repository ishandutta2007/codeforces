#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
int n,m,a[150100],pri[1001000],mnp[1001000],dsu[1001000];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){x=find(x),y=find(y);if(x!=y)dsu[x]=y;}
void sieve(){
	for(int i=2;i<=N;i++){
		if(!pri[i])pri[mnp[i]=++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			pri[i*pri[j]]=true,mnp[i*pri[j]]=j;
			if(!(i%pri[j]))break;
		}
	}
}
set<pair<int,int> >s;
set<int>t[1001000];
int main(){
	sieve();for(int i=1;i<=pri[0];i++)dsu[i]=i;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int x=mnp[a[i]],j=a[i];j!=1;j/=pri[mnp[j]])merge(x,mnp[j]);
	}
	for(int i=1;i<=n;i++){
		vector<int>v;
		for(int x=mnp[a[i]+1],j=a[i]+1;j!=1;j/=pri[mnp[j]])v.push_back(find(mnp[j]));
		sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin());
		int x=find(mnp[a[i]]);
		for(int j=0;j<v.size();j++)for(int k=j+1;k<v.size();k++)s.emplace(v[j],v[k]);
		for(auto y:v){
			if(x<y)s.emplace(x,y);
			if(x>y)s.emplace(y,x);
		}
	}
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		x=find(mnp[a[x]]),y=find(mnp[a[y]]);
		if(x>y)swap(x,y);
		if(x==y)puts("0");
		else if(s.find(make_pair(x,y))!=s.end())puts("1");
		else puts("2");
	}
	return 0;
}