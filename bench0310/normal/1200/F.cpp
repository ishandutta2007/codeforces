#include <bits/stdc++.h>

using namespace std;

const int N=1005;
const int M=2520;
vector<vector<int>> dp(N,vector<int>(M,-2)); //-2:not visited || -1:visited, not yet solved
vector<long long> k(N);
vector<int> m(N);
vector<int> e[N];

int mod(long long a,long long b)
{
    if(a>=0) return a%b;
    else return a+(((-a+b-1)/b))*b;
}

int extract(int id,long long c)
{
    set<int> s={id};
    int now=e[id][mod(c,m[id])];
    long long t=mod(c+k[now],M);
    while(now!=id||t!=c)
    {
        s.insert(now);
        now=e[now][mod(t,m[now])];
        t=mod(t+k[now],M);
    }
    return s.size();
}

int solve(int id,long long c)
{
    c=mod(c+k[id],M);
    int &res=dp[id][c];
    if(res!=-1&&res!=-2) return res;
    if(res==-1) return res=extract(id,c);
    res=-1;
    long long t=solve(e[id][mod(c,m[id])],c);
    return res=t;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&k[i]);
	for(int o=1;o<=n;o++)
    {
        scanf("%d",&m[o]);
        e[o].resize(m[o]);
        for(int i=0;i<m[o];i++) scanf("%d",&e[o][i]);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int id;
        long long c;
        scanf("%d%I64d",&id,&c);
        printf("%d\n",solve(id,c));
    }
	return 0;
}