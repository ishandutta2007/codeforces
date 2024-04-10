#include <bits/stdc++.h>
#define fin freopen("next.in","r",stdin)
#define fout freopen("next.out","w",stdout)
using namespace std;
long long a[1000000],use[1000000],p,c,ans,n;
vector <long long> v[1000000],l[1000000];
void dfs(long long  u, long long len,long long d)
{
	//cout<<u<<'\n';
	use[u]=1;
	for (int i=0;i<v[u].size();i++)
	if ((use[v[u][i]]==0)&&(len+l[u][i]-d<=a[v[u][i]])) 
	dfs(v[u][i],len+l[u][i],min(len+l[u][i],d));
}
int main() 
{
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	for (int i=1;i<=n-1;i++)
	{
		cin>>p>>c;
		v[i+1].push_back(p);
		v[p].push_back(i+1);
		l[i+1].push_back(c);
		l[p].push_back(c);
	}
	dfs(1,0,0);
	for (int i=1;i<=n;i++)
	if (use[i]==0) ans++;
	cout<<ans;
	
}