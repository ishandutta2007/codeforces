#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        int x;
        cin>>x;
        if (x<3) cout<<-1;
        else if (x%2==0) cout<<x/4;
        else if (x%4==1)
        {
            if (x==5) cout<<-1;
            else cout<<x/4-1;
        }
        else
        {
            if (x<12) cout<<-1;
            else cout<<x/4-1;
        }
        cout<<endl;
    }
    return 0;
}