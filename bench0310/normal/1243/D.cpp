#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    set<pair<int,int>> edges;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        edges.insert({a,b});
        edges.insert({b,a});
    }
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    int cnt=0;
    while(!s.empty())
    {
        queue<int> q;
        q.push(*s.begin());
        s.erase(s.begin());
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            vector<int> t;
            for(int b:s)
            {
                if(edges.count({a,b})) continue;
                t.push_back(b);
                q.push(b);
            }
            for(int b:t) s.erase(b);
        }
        cnt++;
    }
    printf("%d\n",cnt-1);
    return 0;
}