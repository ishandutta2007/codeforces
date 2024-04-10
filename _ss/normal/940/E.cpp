#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
ll n,c,a[maxn],f[maxn],s[maxn],v[maxn];

int main()
{
    cin>>n>>c;
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]),s[i]=s[i-1]+a[i];
    deque<ll> q;
    for (int i=1;i<=n;i++)
    {
        while (!q.empty() && a[q.front()]>=a[i]) q.pop_front();
        q.push_front(i);
        if (q.back()<=i-c) q.pop_back();
        v[i]=a[q.back()];
    }
    for (int i=1;i<c;i++) f[i]=s[i];
    for (int i=c;i<=n;i++) f[i]=min(f[i-1]+a[i],f[i-c]+s[i]-s[i-c]-v[i]);
    cout<<f[n];
    return 0;
}