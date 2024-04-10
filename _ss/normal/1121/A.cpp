#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e2+1;
int p[maxn],s[maxn],n,m,k,mp[maxn];
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<=n;i++) mp[s[i]]=max(mp[s[i]],p[i]);
    int x,d=0;
    for (int i=1;i<=k;i++)
    {
        cin>>x;
        if (p[x]<mp[s[x]]) d++;
    }
    cout<<d;
    return 0;
}