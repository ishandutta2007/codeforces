#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;

vector<int> previous;
vector<int> dist;
vector<int> visited;
vector<int> currentparity;

vector<int> ordered;

void bfs(int start)
{
    queue<int> MyQueue;
    MyQueue.push(start);
    dist[start] = 0;
    visited[start] = true;
    while (!MyQueue.empty())
    {
        int k = MyQueue.front();
        ordered.push_back(k);
        MyQueue.pop();
        for (int i = 0; i<G[k].size(); i++)
        {
            if (!visited[G[k][i]]) 
            {
                dist[G[k][i]] = dist[k]+1;
                previous[G[k][i]] = k;
                visited[G[k][i]] = true;
                MyQueue.push(G[k][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if (n%2==1) {cout<<-1; return 0;}
    for (int i = 0; i<n; i++)
    {
        vector<int> temp;
        G.push_back(temp);
    }
    int a, b;
    for (int i = 0; i<n-1; i++)
    {
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for (int i = 0; i<n; i++)
    {
        visited.push_back(0);
    }
    
    for (int i = 0; i<n; i++)
    {
        previous.push_back(-1);
    }

    for (int i = 0; i<n; i++)
    {
        dist.push_back(-1);
    }
    
    int start = 0;
    while (G[start].size()!=1) start++;
    for (int i = 0; i<n; i++) currentparity.push_back(1);
    bfs(start);

    int counter = 0;
    for (int i = n-1; i>=0; i--)
    {
        if (currentparity[ordered[i]]==0) {counter++;}
        else {currentparity[previous[ordered[i]]] = 1 - currentparity[previous[ordered[i]]];}
    }
    cout<<counter-1;
}