#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    map<int,int> tmp;
    ll res=(1ll<<60);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        tmp[a]++;
        if(tmp[a]>=k) res=0;
    }
    vector<array<int,2>> v={{0,0}};
    for(auto [a,c]:tmp) v.push_back({a,c});
    v.push_back({(1<<30),0});
    int m=tmp.size();
    vector<int> cl(m+2,0);
    vector<int> cr(m+2,0);
    vector<ll> sl(m+2,0);
    vector<ll> sr(m+2,0);
    for(int i=1;i<=m;i++)
    {
        cl[i]=cl[i-1]+v[i][1];
        sl[i]=sl[i-1]+ll(v[i][0])*v[i][1];
        if(cl[i]>=k) res=min(res,ll(cl[i])*v[i][0]-sl[i]-min(cl[i]-k,cl[i-1]));
    }
    for(int i=m;i>=1;i--)
    {
        cr[i]=cr[i+1]+v[i][1];
        sr[i]=sr[i+1]+ll(v[i][0])*v[i][1];
        if(cr[i]>=k) res=min(res,sr[i]-ll(cr[i])*v[i][0]-min(cr[i]-k,cr[i+1]));
    }
    for(int i=2;i<=m-1;i++)
    {
        res=min(res,ll(cl[i-1])*(v[i][0]-1)-sl[i-1]+sr[i+1]-ll(cr[i+1])*(v[i][0]+1)+max(0,k-v[i][1]));
    }
    cout << res << "\n";
    return 0;
}