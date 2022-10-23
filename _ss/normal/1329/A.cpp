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
ll n,m,l[N],p[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    ll s=0;
    for (int i=1;i<=m;i++) cin>>l[i],s+=l[i];
    for (int i=1;i<=m;i++)
        if (l[i]+i-1>n)
        {
            cout<<-1;
            return 0;
        }
    if (s<n)
    {
        cout<<-1;
        return 0;
    }
    for (int i=m;i;i--)
    {
        n=max((ll)i,n-l[i]+1);
        p[i]=n;
        n--;
    }
    for (int i=1;i<=m;i++) cout<<p[i]<<" ";
    return 0;
}