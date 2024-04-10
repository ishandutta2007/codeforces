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
    char c1,c2,c3;
    int check=0;
    cin>>c1>>c2;
    for (int i=1;i<=10;i++)
    {
        cin>>c3;
        if (c3==c1 || c3==c2) check=1;
    }
    if (check) cout<<"YES"; else cout<<"NO";
    return 0;
}