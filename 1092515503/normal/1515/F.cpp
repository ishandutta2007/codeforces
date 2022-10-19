#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,X,dsu[300100];
ll a[300100],sum;
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
bool merge(int x,int y){x=find(x),y=find(y);if(x==y)return false;dsu[x]=y;return true;}
vector<pair<int,int> >v[300100];
priority_queue<pair<ll,int> >q;
bool MERGE(int x){
	while(!v[x].empty()&&find(v[x].back().second)==x)v[x].pop_back();
	if(v[x].empty())return false;
	int y=find(v[x].back().second),z=v[x].back().first;v[x].pop_back();
	dsu[y]=x,a[x]+=a[y]-X;
	printf("%d\n",z);
	if(v[x]<v[y])swap(v[x],v[y]);
	while(!v[y].empty())v[x].push_back(v[y].back()),v[y].pop_back();
	q.emplace(a[x],x);
	return true;
}
int main(){
	scanf("%d%d%d",&n,&m,&X);
	for(int i=1;i<=n;i++)dsu[i]=i,scanf("%lld",&a[i]),q.emplace(a[i],i),sum+=a[i];
	if(sum<1ll*(n-1)*X){puts("NO");return 0;}
	puts("YES");
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(merge(x,y))v[x].emplace_back(i,y),v[y].emplace_back(i,x);
	}
	for(int i=1;i<=n;i++)dsu[i]=i;
	while(!q.empty()){
		if(q.top().first<X)break;
		int x=q.top().second;q.pop();
		if(dsu[x]!=x)continue;
		MERGE(x);
	}
	for(int i=1;i<=n;i++){
		if(dsu[i]!=i)continue;
		while(MERGE(i));
	}
	return 0;
}