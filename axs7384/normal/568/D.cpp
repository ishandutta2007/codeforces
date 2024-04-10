#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
struct data
{
	int x,y,z,id;
};
typedef vector<data> vd;
typedef vector<pair<int,int> > vp;
vd a;
vp ans;
int n,m,x,y,z;
inline ll det(int a, int b, int c, int d)
{ 
 	return (ll)a*d-(ll)b*c; 
}
inline ll det(const data &a, const data &b, const data &c) 
{
  ll p=(ll)b.y*c.z-(ll)b.z*c.y;
  ll q=(ll)b.x*c.z-(ll)b.z*c.x;
  ll r=(ll)b.x*c.y-(ll)b.y*c.x;
  return a.x*p-a.y*q+a.z*r;
}
void work(vd &a,int k)
{
	int n=a.size();
	if (n<=k)
	{
		puts("YES");
		printf("%d\n",n+ans.size());
		for (int i=0;i<n;++i)
			printf("%d -1\n",a[i].id);
		for (int i=0;i<ans.size();++i)
			printf("%d %d\n",ans[i].first,ans[i].second);
		exit(0);
	}
	if (!k)
		return;
	vd aa;
	for (int i=3*k*k;i;--i)
	{
		int x=rand()%n,y=rand()%n;
		while (y==x)
			y=rand()%n;
		const data &A=a[x],&B=a[y];
		if (!det(A.x,A.y,B.x,B.y))
			continue;
		aa.clear();
		for (int j=0;j<n;++j)
			if (j!=x&&j!=y&&det(A,B,a[j]))
				aa.push_back(a[j]);
		int t=aa.size();
		if (t>max(k-1,n-n/k))
			continue;
		ans.push_back(mp(a[x].id,a[y].id));
		work(aa,k-1);
		ans.pop_back();
		if (n-t>k)
			return;
	}
}
int main()
{
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		a.push_back(data{x,y,z,i});
	}
	work(a,m);
	puts("NO");
	return 0;
}