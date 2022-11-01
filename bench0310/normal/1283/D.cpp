#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    set<int> vis;
    queue<array<int,2>> q;
    auto add=[&](int x,int now)
    {
        for(int d:{-1,1})
        {
            if(vis.find(x+d)==vis.end())
            {
                vis.insert(x+d);
                q.push({x+d,now+1});
            }
        }
    };
    vector<int> tree(n);
    for(int i=0;i<n;i++)
    {
        cin >> tree[i];
        vis.insert(tree[i]);
    }
    for(int x:tree) add(x,0);
    ll best=0;
    vector<int> res;
    while(m--)
    {
        auto [x,dist]=q.front();
        q.pop();
        best+=dist;
        res.push_back(x);
        add(x,dist);
    }
    cout << best << "\n";
    for(int x:res) cout << x << " ";
    cout << "\n";
    return 0;
}