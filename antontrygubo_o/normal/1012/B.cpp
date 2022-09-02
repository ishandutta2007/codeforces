#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;

vector<vector<int>> G;

vector<bool> visited;
void dfs(int start)
{
    visited[start] = true;
    for (int i = 0; i<G[start].size(); i++) if (!visited[G[start][i]]) dfs(G[start][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
int n, m;
int q;
cin>>n>>m>>q;
int r, c;

vector<bool> rows(n, false);
vector<bool> columns(m, false);

vector<int> first(n, -1);

for (int i = 0; i<m; i++)
{
    vector<int> temp;
    G.push_back(temp);
}

for (int i = 0; i<q; i++)
{
    cin>>r>>c;
    r--;
    c--;
    rows[r] = true;
    columns[c] = true;
    if (first[r]==-1) first[r] = c;
    else {G[c].push_back(first[r]);  G[first[r]].push_back(c);}
}

for(int i = 0; i<m; i++) visited.push_back(false);

int counter = 0;
for (int i = 0; i<m; i++) 
{
    if (!visited[i]) {counter++; dfs(i);}
}

for (int i = 0; i<n; i++) if (rows[i]==false) counter++;
cout<<counter-1;

}