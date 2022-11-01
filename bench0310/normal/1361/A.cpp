#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> g[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<array<int,2>> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i][0];
        v[i][1]=i+1;
    }
    sort(v.begin(),v.end());
    vector<int> now(n+1,0);
    auto out=[](){cout << "-1\n"; exit(0);};
    for(auto [val,a]:v)
    {
        set<int> s;
        for(int to:g[a])
        {
            if(now[to]==val) out();
            if(now[to]!=0) s.insert(now[to]);
        }
        if((int)s.size()<val-1) out();
        now[a]=val;
    }
    for(int i=0;i<n;i++) cout << v[i][1] << " \n"[i==n-1];
    return 0;
}