#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;

vector<vector<int>> G;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    for (int i = 0; i<n; i++) 
    {
        vector<int> temp; G.push_back(temp);
    }
    
    int a, b;
    for (int i = 0; i<n-1; i++)
    {
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    vector<int> visited(n, 0);
    vector<int> count(n, 0);
    vector<int> layer(n, -1);
    queue<int> my;
    int maxx = 0;
    for (int i = 0; i<n; i++) if (G[i].size()==1) {my.push(i); count[i] = 3; layer[i] = 0;}
    while (!my.empty())
    {
        int temp = my.front();
        my.pop();
        if (!visited[temp])
        {
        visited[temp] = true;
        maxx = max(maxx, layer[temp]);
        if (count[temp]<3) {cout<<"No"; return 0;}
        int tempcount = 0;
        for (int j = 0; j<G[temp].size(); j++)
        {
            int t2 = G[temp][j];
            if (!visited[t2])
            {
                tempcount++;
                count[t2]++;
                my.push(t2);  if (layer[t2]!=-1&&layer[t2]!=layer[temp]+1) {cout<<"No"; return 0;}
                layer[t2]=layer[temp]+1;
            }
        }
        if (tempcount>1) {cout<<"No"; return 0;}
        }   
    }
    if (maxx==k) cout<<"Yes";
    else cout<<"No";
    
    
}