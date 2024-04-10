#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=2e5+1,msiz=2,mod=1e9+7,inf=1e18;
string a,b;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,res=0;
    cin>>n>>a>>b;
    for (int i=0;i<n;i++)
        if (a[i]!=b[i])
    {
        if (i<n-1 && a[i]==b[i+1] && a[i+1]==b[i]) i++;
        res++;
    }
    cout<<res;
    return 0;
}