#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> v[n+1];
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin >> l >> r;
        v[l].push_back({r,i});
    }
    vector<int> one(n+1,0);
    vector<bool> lim(n+1,0);
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
    vector<array<int,3>> tmp(n+1,{0,0,0}); //a,b,ra
    for(int i=1;i<=n;i++)
    {
        for(auto a:v[i]) q.push(a);
        auto [ra,a]=q.top();
        q.pop();
        one[a]=i;
        if(ra==i) lim[i]=1;
        if(!q.empty()) tmp[i]={a,q.top()[1],ra};
    }
    vector<int> nxt(n+2,n+1);
    for(int i=n;i>=1;i--)
    {
        nxt[i]=nxt[i+1];
        if(lim[i]==1) nxt[i]=i;
    }
    int second=0;
    for(int i=1;i<=n;i++)
    {
        auto [a,b,ra]=tmp[i];
        if(a==0) continue;
        if(one[b]<=ra||nxt[ra]>=one[b]) second=i;
    }
    if(second!=0) cout << "NO\n";
    else cout << "YES\n";
    for(int i=1;i<=n;i++) cout << one[i] << " \n"[i==n];
    if(second!=0)
    {
        vector<int> two(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(auto a:v[i]) q.push(a);
            auto [ra,a]=q.top();
            q.pop();
            if(i!=second) two[a]=i;
            else
            {
                int b=q.top()[1];
                q.pop();
                two[b]=i;
                q.push({ra,a});
            }
        }
        for(int i=1;i<=n;i++) cout << two[i] << " \n"[i==n];
    }
    return 0;
}