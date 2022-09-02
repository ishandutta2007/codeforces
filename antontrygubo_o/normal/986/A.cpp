#include <bits/stdc++.h>
using namespace std;

int n, m, k, s;
vector<vector<int>> G;
vector<queue<int>> G1;

vector<vector<int>> d;

void kek(int a)
{
    while (!G1[a].empty())
    {
        int k = G1[a].front();
        G1[a].pop();
        for (int i = 0; i<G[k].size(); i++)
        {
            int c = G[k][i];
            if (d[c][a]==-1)
            {
                d[c][a] = d[k][a]+1;
                G1[a].push(c);
            }
        }
    }
}

int main()
{
    cin>>n>>m>>k>>s;
    for (int i = 0; i<n; i++)
    {
        vector<int> temp (k, -1);
        d.push_back(temp);
    }
    for (int i = 0; i<k; i++)
    {
        queue<int> temp;
        G1.push_back(temp);
    }
    int temp;
    for (int i = 0; i<n; i++)
    {
        cin>>temp; G1[temp-1].push(i);
        d[i][temp-1] = 0;
    }
    for (int i = 0; i<n; i++)
    {
        vector<int> temp;
        G.push_back(temp);
    }
    int a, b;
    for (int i = 0; i<m; i++)
    {
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
for (int i = 0; i<k; i++) kek(i);    

for (int i = 0; i<n; i++)
{
    sort(d[i].begin(), d[i].end());
    long long res = 0;
    for (int j = 0; j<s; j++) res+=d[i][j];
    cout<<res<<' ';
}
    
}