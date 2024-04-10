#include <bits/stdc++.h>

using namespace std;

const int N=200005;
vector<int> v[N];
vector<int> one(N,-1);
vector<int> two(N,-1);

void bfs(int src,vector<int> &d)
{
    queue<int> q;
    q.push(src);
    d[src]=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a])
        {
            if(d[to]==-1)
            {
                q.push(to);
                d[to]=d[a]+1;
            }
        }
    }
}

int attempt(set<pair<int,int>> &a,set<pair<int,int>> &b)
{
    if(a.size()==1) return 0;
    int res=(*a.rbegin()).first;
    if((*b.rbegin()).second!=(*a.rbegin()).second) res+=(*b.rbegin()).first;
    else res+=res+=(*prev(prev(b.end()))).first;
    return res;
}

int solve_one(vector<pair<int,int>> a)
{
    int res=0;
    sort(a.begin(),a.end());
    multiset<int> s;
    for(auto [ignore,t]:a) s.insert(two[t]);
    for(auto [ignore,t]:a)
    {
        s.erase(s.find(two[t]));
        if(!s.empty()) res=max(res,one[t]+(*s.rbegin()));
    }
    return res;
}

int solve_two(vector<pair<int,int>> a)
{
    int res=0;
    sort(a.begin(),a.end(),greater<pair<int,int>>());
    multiset<int> s;
    for(auto [ignore,t]:a) s.insert(one[t]);
    for(auto [ignore,t]:a)
    {
        s.erase(s.find(one[t]));
        if(!s.empty()) res=max(res,two[t]+(*s.rbegin()));
    }
    return res;
}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<int> pos(k);
    for(int i=0;i<k;i++) scanf("%d",&pos[i]);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1,one);
    bfs(n,two);
    map<int,set<pair<int,int>>> a,b;
    for(int x:pos)
    {
        a[one[x]-two[x]].insert({one[x],x});
        b[one[x]-two[x]].insert({two[x],x});
    }
    int res=0;
    for(auto &[diff,ignore]:a)
    {
        res=max(res,attempt(a[diff],b[diff]));
        res=max(res,attempt(b[diff],a[diff]));
    }
    vector<pair<int,int>> temp;
    for(int x:pos) temp.push_back({one[x]-two[x],x});
    res=max(res,solve_one(temp));
    res=max(res,solve_two(temp));
    res++;
    res=min(res,one[n]);
    printf("%d\n",res);
    return 0;
}