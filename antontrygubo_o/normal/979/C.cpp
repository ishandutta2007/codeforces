#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> visited;
vector<int> previous;
long long n;
long long counter = 0;
void clear()
{
    for (int i = 0; i<visited.size(); i++) visited[i] = 0;
}

void dfs(int start)
{
    visited[start] = true;
    for (int i = 0; i<G[start].size(); i++)
    {
        int k = G[start][i];
        if (!visited[k]&&previous[k]!=n) {previous[k] = start; dfs(k); counter++;}
    }
}



int main()
{
cin>>n;
for (int i = 0; i<n; i++) visited.push_back(0);
for (int i = 0; i<n; i++) previous.push_back(-1);
long long x, y;
cin>>x>>y; x--; y--;
for (int i = 0; i<n; i++)
{
    vector<int> temp; G.push_back(temp);
}
long long a, b;
for (int i = 0; i<n-1; i++)
{
    cin>>a>>b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
}

dfs(x);

long long t = y;
while (t!=x)
{
    int temp = previous[t];
    previous[t] = n;
    t = temp;
}
previous[x] = n;
clear();
counter = 0;
long long res1 = 0;
long long res2 = 0;
dfs(x);
res1 = counter;
clear();
counter = 0;
dfs(y);
res2 = counter;

long long kek = n*(n-1)-(res1+1)*(res2+1);
cout<<kek;
}