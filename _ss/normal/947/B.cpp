#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+10,msiz=2,mod=1e9+7,inf=1e18;
ll v[maxn],t[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>v[i];
    for (int i=1;i<=n;i++) cin>>t[i];
    priority_queue<ll, vector<ll>, greater<ll> > q;
    ll s=0;
    for (int i=1;i<=n;i++)
    {
        q.push(v[i]+s);
        s+=t[i];
        ll tmp=0;
        while (!q.empty() && q.top()<=s)
        {
            tmp+=q.top()-s+t[i];
            q.pop();
        }
        cout<<tmp+t[i]*q.size()<<" ";
    }
    return 0;
}