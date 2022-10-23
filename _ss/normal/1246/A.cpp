#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vt) vt.begin(),vt.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
int n,p;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>p;
    n-=p;
    int d=1,tmp;
    while (n>=d)
    {
        tmp=__builtin_popcount(n);
        if (tmp<=d) break;
        n-=p;
        d++;
    }
    if (tmp<=d && n>=d) cout<<d;
    else cout<<-1;
    return 0;
}