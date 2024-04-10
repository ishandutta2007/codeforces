#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k1,k2,x,m1=0,m2=0;
        cin>>n>>k1>>k2;
        for (int i=1;i<=k1;i++)
        {
            cin>>x;
            m1=max(m1,x);
        }
        for (int i=1;i<=k2;i++)
        {
            cin>>x;
            m2=max(m2,x);
        }
        if (m1>m2) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}