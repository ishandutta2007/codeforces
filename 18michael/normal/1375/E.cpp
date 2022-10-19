#include<bits/stdc++.h>
using namespace std;
int n;
int a[1002],to[1002];
typedef pair<int,int> P;
vector<P> vec;
inline bool cmp(int x,int y)
{
	return a[x]==a[y]? (x<y):(a[x]<a[y]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),to[i]=i;
	sort(to+1,to+n+1,cmp);
	for(int i=1;i<=n;++i)a[to[i]]=i;
	for(int i=n;i;--i)for(int j=a[i]+1;j<=i;++j)vec.push_back(P(to[j],i)),swap(a[to[j]],a[i]),swap(to[j],to[a[to[j]]]);
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();++i)printf("%d %d\n",vec[i].first,vec[i].second);
	return 0;
}