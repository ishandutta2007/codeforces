#include <bits/stdc++.h>
using namespace std;
const int N = 102;
const int INF = N * 100000;

int n;
vector<int> a[5][5];
int sum[5][5];

int k;
int c[5];
void dfs(int x)
{
    c[x]=k;
    for(int i=1;i<=4;++i)
        if(!c[i] && sum[x][i])
            dfs(i);
}

int ans;
void stg()
{
    for(int x=1;x<=4;++x)
        c[x]=0;
    k=0;
    for(int x=1;x<=4;++x)
    {
        if(!c[x])
        {
            ++k;
            dfs(x);
        }
    }
    int zz[5]={},kk[5]={},sv[5]={};
    for(int i=1;i<=4;++i)
    {
        int q=0,s=0;
        for(int j=1;j<=4;++j)
        {
            q+=a[i][j].size();
            s+=sum[i][j];
        }
        if(q%2==0)
            zz[c[i]]++;
        else
            kk[c[i]]++;
        sv[c[i]]+=s;
    }
    for(int i=1;i<=k;++i)
    {
        if(kk[i]==0 || (kk[i]==2))
            ans=max(ans,sv[i]/2);
    }
}

void rec(int x,int y)
{
    if(x==5)
    {
        stg();
        return;
    }
    if(y!=4)
        rec(x,y+1);
    else
        rec(x+1,1);
    if(!a[x][y].empty())
    {
        int t=a[x][y].back();
        a[x][y].pop_back();
        a[y][x].pop_back();
        sum[x][y]-=t;
        sum[y][x]-=t;
        if(y!=4)
            rec(x,y+1);
        else
            rec(x+1,1);
        a[x][y].push_back(t);
        a[y][x].push_back(t);
        sum[x][y]+=t;
        sum[y][x]+=t;
    }
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int c1, v, c2;
		cin >> c1 >> v >> c2;
		a[c1][c2].push_back(v);
		sum[c1][c2] += v;

        a[c2][c1].push_back(v);
        sum[c2][c1]+=v;
	}
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
        {
			sort(a[i][j].begin(), a[i][j].end());
			reverse(a[i][j].begin(), a[i][j].end());
        }
	}
	rec(1,1);
	cout<<ans<<endl;
	return 0;
}