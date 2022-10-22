#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long 
int n;
const int N=1e6;
vector<int> ve[N];
vector<char> ans[N];
map<int,int> M,p;
int l=1,m[N];
struct re{
	int a,b,c,d;
}e[N];
int head[N];
void arr2(int x,int y,int z)
{
	e[++l].a=head[x];
	e[l].b=y;
	e[l].c=0;
	e[l].d=z;
	head[x]=l;
}
void arr(int x,int y,int z)
{
	arr2(x,y,z); arr2(y,x,z);
}
void dfs(int x)
{
	for (int u=head[x];u;u=head[x])
	{
		int v=e[u].b;
		if (e[u].c==0)
		{
			e[u].c=e[u^1].c=1;
			head[x]=e[u].a;
			dfs(v);
			if (x<v) ans[min(x,v)][e[u].d]='L';
			else ans[min(x,v)][e[u].d]='R';
		} else head[x]=e[u].a;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int cnt=n;
	rep(i,1,n)
	{
		cin>>m[i];
		rep(j,1,m[i])
		{
			int x;
			cin>>x;
			ve[i].push_back(x);
			M[x]++;
			if (!p[x]) p[x]=++cnt;
			arr(i,p[x],j);
		}
		ans[i].resize(m[i]+5);
	}
	bool tt=0;
	for (auto v:M)
	{
		if (v.second%2!=0) tt=1;
    }
    if (tt)
    {
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    rep(i,1,n) dfs(i);
    rep(i,1,n)
    {
    	rep(j,1,m[i]) cout<<ans[i][j];
    	cout<<"\n";
    }
	return 0;
}