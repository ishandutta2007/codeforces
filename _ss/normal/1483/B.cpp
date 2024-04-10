#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10;
int n,del[N],a[N],nxt[N],prv[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i],nxt[i]=i%n+1,prv[i]=(i-2+n)%n+1,del[i]=0;
        queue<pii> q;
        vi ans;
        for (int i=1;i<=n;i++)
            if (__gcd(a[i],a[nxt[i]])==1) q.push(mp(i,nxt[i]));
        while (!q.empty())
        {
            pii p=q.front();
            q.pop();
            if (del[p.fi]) continue;
            ans.eb(p.se);
            del[p.se]=1;
            int nx=nxt[p.se];
            nxt[p.fi]=nx;
            prv[nx]=p.fi;
            if (__gcd(a[p.fi],a[nx])==1) q.push(mp(p.fi,nx));
        }
        cout<<ans.size()<<" ";
        for (int x : ans) cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}