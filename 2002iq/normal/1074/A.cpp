#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<int,int> m;
int arr[100005];
vector<int> v;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for (int i=0;i<a;i++)
	scanf("%d",&arr[i]);
	arr[a]=1e9;
	sort(arr,arr+a);
	while (b--)
	{
		int x1,x2,y;
		scanf("%d%d%d",&x1,&x2,&y);
		if (!m.count(y))
		m[y]=1;
		if (m[y]==x1)
		m[y]=x2+1;
	}
	for (auto p:m)
	v.push_back(p.second);
	sort(v.begin(),v.end());
	int ans=(1<<30),r=0;
	for (int i=0;i<=a;i++)
	{
		while (r<v.size() && v[r]<=arr[i])
		r++;
		ans=min(ans,i+(int)v.size()-r);
	}
	printf("%d",ans);
}