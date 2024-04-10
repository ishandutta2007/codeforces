#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v[n+1];
    int d=0;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        d=max({d,int(v[a].size()),int(v[b].size())});
    }
    vector<array<int,2>> res;
    function<void(int,int,int)> go=[&](int a,int p,int t)
    {
        res.push_back({a,t});
        int c=(int(v[a].size())-(a!=1));
        int e=t;
        auto one=[&]()
        {
            t=e-1-c;
            res.push_back({a,t});
        };
        if(a!=1&&t==d) one();
        for(int to:v[a])
        {
            if(to==p) continue;
            go(to,a,t+1);
            res.push_back({a,t+1});
            c--;
            t++;
            if(a!=1&&t==d) one();
        }
        if(a!=1&&t!=e-1) res.push_back({a,e-1});
    };
    go(1,0,0);
    cout << res.size() << "\n";
    for(auto [a,t]:res) cout << a << " " << t << "\n";
    return 0;
}