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

int k, n;

vector<int> pr;

vector<int> topsort;
vector<int> visited;
vector<vector<int>> G;
vector<int> get_back;
vector<int> not_back;
vector<int> min_leave;
vector<int> waiting;
void dfs(int start)
{
    visited[start] = true;
    for (auto s: G[start]) if (!visited[s]) dfs(s);
    if (G[start].size()==1&&start!=1) min_leave[start] = 0;
    else 
    {
        min_leave[start] = 1000000;
        for (auto s:G[start]) if (s!=pr[start]) min_leave[start] = min(min_leave[start], min_leave[s]+1);
    }
    if (G[start].size()==1&&start!=1) {get_back[start] = 1; not_back[start] = 1; waiting[start] = 0;}
    else
    {
        int maxwaiting = 0;
        for (auto s:G[start]) if (s!=pr[start]&&min_leave[s]<=k-1) get_back[start]+=get_back[s];
        for (auto s:G[start]) if (s!=pr[start])
        {
            if (min_leave[s]<=k-1) maxwaiting = max(maxwaiting, waiting[s]);
            else maxwaiting = max(maxwaiting, not_back[s]);
        }
        not_back[start] = get_back[start] + maxwaiting;
        waiting[start] = maxwaiting;
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>k;
    G.resize(n+1);
    pr.resize(n+1);
    pr[1] = 1;
    for (int i = 2; i<=n; i++) {cin>>pr[i]; G[pr[i]].push_back(i); G[i].push_back(pr[i]);}
    visited.resize(n+1);
    get_back.resize(n+1);
    not_back.resize(n+1);
    min_leave.resize(n+1);
    waiting.resize(n+1);
    dfs(1);
    cout<<not_back[1];
    
}