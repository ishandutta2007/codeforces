#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<ll> a(n+1,0);
    vector<ll> b(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    ll lim=2000000000000;
    ll l=-1,r=lim+1;
    while(l<r-1)
    {
        ll m=(l+r)/2;
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
        vector<ll> now=a;
        bool ok=1;
        for(int i=1;i<=n;i++) if((a[i]/b[i])<k) q.push({a[i]/b[i],i});
        for(int i=0;i<=k-1;i++)
        {
            if(q.empty()) break;
            auto [d,x]=q.top();
            q.pop();
            if(d<i) ok=0;
            now[x]+=m;
            if((now[x]/b[x])<k) q.push({now[x]/b[x],x});
        }
        if(ok) r=m;
        else l=m;
    }
    if(r<=lim) cout << r << "\n";
    else cout << "-1\n";
    return 0;
}