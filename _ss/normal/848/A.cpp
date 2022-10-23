#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k,t=400,d=1;
    cin>>k;
    if (!k)
    {
        cout<<"a";
        return 0;
    }
    k*=2;
    while (k)
    {
        while (t*(t-1)>k) t--;
        k-=t*(t-1);
        for (int i=1;i<=t;i++) cout<<(char)((int)('a')+d-1);
        d++;
    }
    return 0;
}