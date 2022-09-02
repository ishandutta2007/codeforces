#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int n, l;
ll S;

vector<int> pr;
vector<int> visited;
vector<vector<int>> G;
vector<int> depth;
vector<vector<int>> ancestor;
vector<ll> weight;
vector<ll> weightup;
vector<int> curlen;
vector<ll> cursum;

int counter = 0;

int anc(int v, int k)
{
    if (depth[v]<k) return -1;
    bitset<40> K(k);
    for (int i = 39; i>=0; i--) if (K[i]==1) v = ancestor[v][i];
    return v;

}

ll summ(int v, int k)
{
    if (k==depth[v]+1) return weightup[v];
    int v1 = anc(v, k);
    return weightup[v] - weightup[v1];
}

int maxx(int v, ll S)
{
    int l = 0;
    int r = depth[v]+1;
    if (summ(v, r)<=S) return r;
    while (r-l>1)
    {
        int mid = (l+r)/2;
        if (summ(v, mid)<=S) l = mid;
        else r = mid;
    }
    return l;
}

void dfs(int start)
{
    visited[start] = true;
    depth[start] = depth[pr[start]] + 1;
    if (depth[start]>0) ancestor[start].push_back(pr[start]);
    int deg = 1;
    int curdepth = 2;
    while (curdepth<=depth[start]) 
    {
        ancestor[start].push_back(ancestor[ancestor[start][deg-1]][deg-1]);
        deg++;
        curdepth*=2;
    }
    if (start==1) weightup[start] = weight[start];
    else weightup[start] = weightup[pr[start]] + weight[start];
    
    
    for (auto s : G[start]) if (!visited[s]) dfs(s);
    
    if (G[start].size()==1&&start!=1) {curlen[start] = 1; cursum[start] = weight[start]; counter++;}
    else
    {
        int maxdepth = 0;
        for (auto s: G[start]) if (s!=pr[start])
        {
            int res = maxx(start, S - cursum[s]);
            res = min(res, l - curlen[s]);
            maxdepth = max(maxdepth, res);
        }
        if (maxdepth==0) {curlen[start] = 1; cursum[start] = weight[start]; counter++;}
        else for (auto s: G[start]) if (s!=pr[start])
        {
            int res = maxx(start, S - cursum[s]);
            res = min(res, l - curlen[s]);
            if (maxdepth==res) 
            {
                curlen[start] = curlen[s] + 1;
                cursum[start] = cursum[s] + weight[start];
                break;
            }
        }
    }
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>l>>S;
    
    G.resize(n+1);
    pr.resize(n+1);
    visited.resize(n+1);
    weight.resize(n+1);
    weightup.resize(n+1);
    curlen.resize(n+1);
    cursum.resize(n+1);
    depth.resize(n+1);
    ancestor.resize(n+1);
    
    pr[1] = 1;
    depth[1] = -1;

    for (int i = 1; i<=n; i++) {cin>>weight[i]; if (weight[i]>S) {cout<<-1; return 0;}}
    for (int i = 2; i<=n; i++) {cin>>pr[i]; G[pr[i]].push_back(i); G[i].push_back(pr[i]);}
    
    dfs(1);

    cout<<counter;
}