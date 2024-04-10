#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,inf=1e18;
pii a[N];
int n;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].fi;
    for (int i=1;i<=n;i++) cin>>a[i].se;
    a[n+1].fi=inf;
    sort(a+1,a+n+1);
    ll res=0,s=0,cur=0;
    priority_queue<ll> q;
    for (int i=1;i<=n;i++)
    {
        cur=a[i].fi;
        q.push(a[i].se);
        s+=a[i].se;
        while (a[i+1].fi==a[i].fi) i++,q.push(a[i].se),s+=a[i].se;
        while (!q.empty() && cur<a[i+1].fi)
        {
            s-=q.top();
            q.pop();
            cur++;
            res+=s;
        }
    }
    cout<<res;
    return 0;
}