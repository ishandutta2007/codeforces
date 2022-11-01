#include <bits/stdc++.h>

using namespace std;
const long long mod=1000000007;

long long fastpow(long long b,long long e)
{
    long long res=1;
    while(e)
    {
        if(e&1) res*=b;
        if(res>=mod) res%=mod;
        b*=b;
        if(b>=mod) b%=mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long n,k;
    cin >> n >> k;
    vector<int> v[n+1];
    for(int i=0;i<n-1;i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        if(w==1) continue;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> id(n+1,0);
    vector<long long> num(n+1,0);
    vector<bool> vis(n+1,0);
    queue<int> q;
    for(int o=1;o<=n;o++)
    {
        if(vis[o]) continue;
        id[o]=o;
        vis[o]=1;
        q.push(o);
        while(!q.empty())
        {
            int e=q.front();
            q.pop();
            for(int i=0;i<(int)v[e].size();i++)
            {
                if(!vis[v[e][i]])
                {
                    q.push(v[e][i]);
                    vis[v[e][i]]=1;
                    id[v[e][i]]=o;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) num[id[i]]++;
    long long res=fastpow(n,k);
    for(int i=1;i<=n;i++) res-=fastpow(num[i],k);
    while(res<0) res+=mod;
    cout << res << endl;
    return 0;
}