#include<bits/stdc++.h>
using namespace std;
int n,a[1010],ord[1010];
bool cmp(int x,int y){
	if(a[x]!=a[y])return a[x]<a[y];
	return x<y;
}
vector<pair<int,int> >v;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ord[i]=i;
	sort(ord+1,ord+n+1,cmp);
//	for(int i=1;i<=n;i++)printf("%d ",ord[i]);puts("");
	for(int i=1;i<=n;i++)for(int j=1;j<=n-i;j++)if(ord[j]>ord[j+1])swap(ord[j],ord[j+1]),v.push_back(make_pair(ord[j],ord[j+1]));
//	for(int i=1;i<=n;i++)printf("%d ",ord[i]);puts("");
	printf("%d\n",v.size());
	for(auto i:v)printf("%d %d\n",i.first,i.second);
	return 0;
}