#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
ll cnt[N],mark[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    for (int i=1,x;i<=n;i++)
    {
        cin>>x;
        if (mark[x%m])
        {
            cout<<0;
            return 0;
        }
        cnt[x%m]=x;
        mark[x%m]=1;
    }
    ll res=1;
    for (int i=0;i<m;i++)
        for (int j=i+1;j<m;j++)
            if (mark[i] && mark[j]) res=res*abs(cnt[i]-cnt[j])%m;
    cout<<res;
    return 0;
}