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

vector<bool> visited;
vector<vector<int>> G;
vector<int> color;

vector<vector<int>> colnodes;

int idx = -1;
void dfs(int start)
{
    visited[start] = true;
    color[start] = idx;
    colnodes[idx].push_back(start);
    for (int i = 0; i<G[start].size(); i++) if (!visited[G[start][i]]) dfs(G[start][i]);
}


vector<int> d;
vector<int> pr;


void bfs(int start, int kek = -1)
{
    visited[start] = true;
    pr[start] = -1;
    queue<int> myQ;
    myQ.push(start);
    d[start] = 0;
    if (kek!=-1)
    {
        visited[kek] = true;
        pr[kek] = -1;
        myQ.push(kek);
        d[kek] = 0;
    }
    while (!myQ.empty())
    {
        int t = myQ.front();
        myQ.pop();
        for (int i = 0; i<G[t].size(); i++)
        {
            int t1 = G[t][i];
            if (!visited[t1]) {d[t1] = d[t] + 1; visited[t1] = true; myQ.push(t1); pr[t1] = t;}
        }
    }
}

vector<int> diam;

set<pair<int, int>> mySet;

void init(int col)
{
    for (int i = 0; i<colnodes[col].size(); i++) {visited[colnodes[col][i]] = false; d[colnodes[col][i]] = -1; pr[colnodes[col][i]] = -1;}
    bfs(colnodes[col][0]);
    int maxx = -1;
    int cur;
    for (int i = 0; i<colnodes[col].size(); i++) if (d[colnodes[col][i]]>maxx) {maxx = d[colnodes[col][i]]; cur = colnodes[col][i];}
    for (int i = 0; i<colnodes[col].size(); i++) {visited[colnodes[col][i]] = false; d[colnodes[col][i]] = -1; pr[colnodes[col][i]] = -1;}
    bfs(cur);
    maxx = -1;
    int cur1;
    for (int i = 0; i<colnodes[col].size(); i++) if (d[colnodes[col][i]]>maxx) {maxx = d[colnodes[col][i]]; cur1 = colnodes[col][i];}
    ll diameter = d[cur1];
    diam[col] = diameter;
    int radius = diameter/2;
    for (int i = 0; i<radius; i++) cur1 = pr[cur1];
    mySet.insert(make_pair(diameter-radius,  cur1));
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    G.resize(n+1);
    visited.resize(n+1);
    color.resize(n+1);
    pr.resize(n+1);
    d.resize(n+1);
    int com = n-m;
    diam.resize(com);
    colnodes.resize(com);
    
    int a, b;
    for (int i = 0; i<m; i++) 
    {
        cin>>a>>b; G[a].push_back(b); G[b].push_back(a);
    }
    
    
    for (int i = 1; i<=n; i++) if (!visited[i])
    {
        idx++; dfs(i);
    }
    
    
    for (int i = 0; i<com; i++) init(i);
    //print(diam);
    
    //for (auto it = mySet.begin(); it!=mySet.end(); it++) cout<<it->first<<' '<<it->second<<endl;
    
    auto it = mySet.end();
    it--;
    
    int result = diam[0];
    for (int i = 0; i<com; i++) result = max(result, diam[i]);
    if (com==1) {cout<<diam[0]; return 0;}
    int t1 = it->first;
    it--;
    int t2 = it->first;
    if (com>=3)
    {
        it--;
        int t3 = it->first;
        result = max(result, t2+t3+2);
        it++;
    }
    it++;
    result = max(result, t1+t2+1);
    cout<<result<<endl;
    for (auto it1 = mySet.begin(); it1!=it; it1++) cout<<it->second<<' '<<it1->second<<endl;
    
    
}