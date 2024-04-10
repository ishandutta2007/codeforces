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

int gcd(int a,int b)
{
    while (b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    int x,y;
    for (int i=1;i<=t;i++)
    {
        cin>>x>>y;
        if (gcd(x,y)==1) cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
    return 0;
}