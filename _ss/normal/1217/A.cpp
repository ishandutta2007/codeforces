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
    int t,a,b,c;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if (a<=b) c-=b+1-a,a=b+1;
        if (c<0) cout<<0; else cout<<(c+a-b-1)-max((a-b+c)/2,a-b-1)+1;
        cout<<endl;
    }
    return 0;
}