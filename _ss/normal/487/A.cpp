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
    ll h,a,d,h1,a1,d1,h2,a2,d2;
    cin>>h1>>a1>>d1>>h2>>a2>>d2>>h>>a>>d;
    ll res=inf;
    for (int i=0;i<=200;i++)
        for (int j=0;j<=200;j++)
        if (a1+i>d2)
        {
            if (d1+j>a2) res=min(res,i*a+j*d);
            else
            {
                ll tmp=(h2-1)/(a1+i-d2)+1;
                tmp=(a2-j-d1)*tmp+1;
                res=min(res,i*a+j*d+max((ll)0,tmp-h1)*h);
            }
        }
    cout<<res;
    return 0;
}