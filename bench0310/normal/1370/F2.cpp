#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

array<int,2> query(vector<int> v)
{
    cout << "? " << v.size() << "\n";
    for(int x:v) cout << x << " ";
    cout << "\n";
    cout.flush();
    array<int,2> a;
    cin >> a[0] >> a[1];
    if(a[0]==-1) exit(0);
    return a;
}

void solve(int a,int b)
{
    cout << "! " << a << " " << b << "\n";
    cout.flush();
    string s;
    cin >> s;
    if(s=="Incorrect") exit(0);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n+1);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> q;
        for(int i=1;i<=n;i++) q.push_back(i);
        auto [root,dist]=query(q);
        q.clear();
        vector<int> depth(n+1,0);
        vector<int> tin(n+1,0);
        vector<int> tout(n+1,0);
        int tcnt=1;
        int mx=0;
        function<void(int,int)> dfs=[&](int a,int p)
        {
            if(p!=-1) depth[a]=depth[p]+1;
            mx=max(mx,depth[a]);
            tin[a]=tcnt++;
            for(int to:v[a])
            {
                if(to==p) continue;
                dfs(to,a);
            }
            tout[a]=tcnt-1;
        };
        dfs(root,-1);
        int l=(dist+1)/2-1,r=min(dist,mx)+1;
        int one=0;
        while(l<r-1)
        {
            int m=(l+r)/2;
            for(int i=1;i<=n;i++) if(depth[i]>=m) q.push_back(i);
            auto [x,d]=query(q);
            if(d==dist)
            {
                l=m;
                one=x;
            }
            else r=m;
            q.clear();
        }
        if(l==dist)
        {
            solve(one,root);
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(depth[i]==dist-l&&(tin[one]<tin[i]||tout[i]<tin[one])) q.push_back(i);
        }
        int two=query(q)[0];
        solve(one,two);
    }
    return 0;
}