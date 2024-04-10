#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> w(n+1,0);
    for(int i=1;i<=n;i++) cin >> w[i];
    vector<set<array<int,2>>> s(n+1);
    vector<int> req(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        req[a]++;
        req[b]++;
        s[a].insert({b,i});
        s[b].insert({a,i});
    }
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=n;i++) if(req[i]<=w[i]) q.push(i);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto [b,i]:s[a])
        {
            res.push_back(i);
            s[b].erase({a,i});
            req[b]--;
            if(req[b]<=w[b]) q.push(b);
        }
        s[a].clear();
    }
    reverse(res.begin(),res.end());
    if((int)res.size()==m)
    {
        cout << "ALIVE\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
    }
    else cout << "DEAD\n";
    return 0;
}