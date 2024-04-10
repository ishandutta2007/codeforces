#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
#define pb push_back
const int MAXN=10005;

vector<int> uu[MAXN];
int num[4];
bool vis[MAXN];
vector<int> dfs(int l,int r)
{
	int x=0;
	for(int i=l;i<=r;i++)x=x*10+num[i];
	vector<int> res;res.pb(x);res.pb(-x);
	if(l==r)return res;
	for(int mid=l;mid<r;++mid)
	{
		vector<int> ul=dfs(l,mid),ur=dfs(mid+1,r);
		for(auto jl:ul)
			for(auto jr:ur)
			{
				res.pb(jl+jr);
				res.pb(jl*jr);
			}
	}
	return res;
}
void init()
{
	for(int i=0;i<=9999;i++)
	{
		int x=i;
		for(int j=3;j>=0;j--,x/=10)num[j]=x%10;
		vector<int> u=dfs(0,3);
		sort(u.begin(),u.end());
		for(auto j:u)
			if(j>=0 && j<=9999 && !vis[j]){vis[j]=1;uu[j].pb(i);}
		for(auto j:u)if(j>=0 && j<=9999)vis[j]=0;
	}
}

int k,m;
void print(int x)
{
	int t[4];
	for(int i=0;i<4;i++,x/=10)t[i]=x%10;
	for(int i=3;i>=0;i--)putchar(t[i]+'0');
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    init();
    scanf("%d%d",&k,&m);
    for(int i=1;i<=9999;i++)
    	for(auto j:uu[i])
    	{
			print(abs(i-k));print(j);putchar('\n');
    		--m;if(!m)return 0;
    	}
    return 0;
}