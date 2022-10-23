#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e3+1,msiz=2,mod=1e9+7,inf=2e9;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x,t,d,h;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>n>>x;
        int m1=-inf,m2=-inf;
        for (int j=1;j<=n;j++)
        {
            cin>>d>>h;
            m1=max(m1,d);
            m2=max(m2,d-h);
        }
        x-=m1;
        if (x<=0) cout<<1;
        else
        {
            if (m2<=0) cout<<-1;
            else cout<<(x+m2-1)/m2+1;
        }
        cout<<endl;
    }
    return 0;
}