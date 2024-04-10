#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(2*n,0);
    for(int i=0;i<2*n;i++) cin >> x[i];
    vector<int> v[2*n+(1<<20)];
    auto solve=[&](int m)->vector<int>
    {
        int s=(1<<m)-1;
        vector<int> d(2*n+s+1,0);
        auto add=[&](int a,int b)
        {
            v[a].push_back(b);
            v[b].push_back(a);
            d[a]++; d[b]++;
        };
        for(int i=0;i<2*n;i+=2) add(i,i+1);
        for(int i=0;i<2*n;i++) add(i,2*n+(x[i]&s));
        vector<bool> vis(3*n,0);
        auto id=[&](int a,int b)->int
        {
            if(a>b) swap(a,b);
            if(b>=2*n) return a;
            else return 2*n+a/2;
        };
        bool ok=1;
        for(int i=0;i<=2*n+s;i++) ok&=((d[i]%2)==0);
        vector<int> euler;
        function<void(int)> go=[&](int a)
        {
            while(!v[a].empty())
            {
                int to=v[a].back();
                v[a].pop_back();
                if(vis[id(a,to)]) continue;
                vis[id(a,to)]=1;
                go(to);
            }
            if(a<2*n) euler.push_back(a);
        };
        go(0);
        euler.pop_back();
        ok&=((int)euler.size()==2*n);
        if(!ok)
        {
            for(int i=0;i<=2*n+s;i++) v[i].clear();
            return {};
        }
        if(euler[1]!=1) rotate(euler.begin(),euler.end()-1,euler.end());
        return euler;
    };
    int l=0,r=21;
    while(l<r-1)
    {
        int m=(l+r)/2;
        if(!solve(m).empty()) l=m;
        else r=m;
    }
    vector<int> res=solve(l);
    cout << l << "\n";
    for(int i=0;i<2*n;i++) cout << res[i]+1 << " \n"[i==2*n-1];
    return 0;
}