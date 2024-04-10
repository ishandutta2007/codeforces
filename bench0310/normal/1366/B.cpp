#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    auto solve=[](int a,int b,int c,int d)->bool{return (max(a,c)<=min(b,d));};
    while(t--)
    {
        int n,x,m;
        cin >> n >> x >> m;
        vector<array<int,2>> a(m);
        for(int i=0;i<m;i++) cin >> a[i][0] >> a[i][1];
        vector<array<int,2>> z={{x,x}};
        for(auto [l,r]:a)
        {
            bool ok=0;
            for(auto [c,d]:z) ok|=solve(c,d,l,r);
            if(ok) z.push_back({l,r});
        }
        vector<array<int,2>> v;
        for(auto [l,r]:z)
        {
            v.push_back({l,1});
            v.push_back({r+1,2});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<(int)v.size();i++) if(v[i][1]==2) v[i][1]=-1;
        int now=v[0][0];
        int cnt=0;
        int res=0;
        for(auto [pos,c]:v)
        {
            if(cnt==0) now=pos;
            cnt+=c;
            if(cnt==0) res+=(pos-now);
        }
        cout << res << "\n";
    }
    return 0;
}