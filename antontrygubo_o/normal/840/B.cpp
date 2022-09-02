#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

vector<int> val;

const ll p = 1e9 + 9;

int n, m;

vector<vector<pair<int, int>>> G;


vector<vector<pair<int, int>>> first;
vector<bool> visited;
void dfs(int start)
{
    visited[start] = 1;
    for (int i = 0; i<G[start].size(); i++)
    {
        if (!visited[G[start][i].first])
        {
            pair<int, int> temp = G[start][i];
            first[start].push_back(temp);
            dfs(temp.first);
        }
    }
}

int f(int k)
{
    if (k==0) return 1;
    if (k==1) return 0;
    if (k==-1) return -1;
}

vector<int> answer;

void rebuild(int start)
{
    if (first[start].size()==0) return;
    for (int i = 0; i<first[start].size(); i++) rebuild(first[start][i].first);
    for (int i = 0; i<first[start].size(); i++) if (val[first[start][i].first]==1) {answer.push_back(first[start][i].second); val[first[start][i].first] = 0; val[start] = f(val[start]);}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    val.resize(n+1);
    first.resize(n+1);
    visited.resize(n+1);
    
    for (int i = 1; i<=n; i++) cin>>val[i];
    bool check = false;
    int sum = 0;
    for (int i = 1; i<=n; i++)
    {
        if (val[i]==-1) check = true;
        sum+=val[i];
    }
    
    if (!check&&(sum%2==1)) {cout<<-1; return 0;}
    
    G.resize(n+1);
    int a, b;
    for (int i = 1; i<=m; i++)
    {
        cin>>a>>b;
        G[a].push_back(make_pair(b, i));
        G[b].push_back(make_pair(a, i));
    }
    
    int start = 1;
    for (int i = 1; i<=n; i++) if (val[i]==-1) start = i;
    
    dfs(start);
    rebuild(start);
    cout<<answer.size()<<endl;
    for (int i = 0; i<answer.size(); i++) cout<<answer[i]<<endl;
    

}