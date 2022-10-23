#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
int a[maxn],n;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x;
    for (int i=1;i<=n;i++) cin>>x,a[x]++;;
    int d=0;
    for (int i=1;i<=100;i++)
    if (a[i])
    {
        int check=0;
        for (int j=1;j<=100;j++)
            if (j!=i && i%j==0 && a[j]) check=1;
        if (!check) d++;
    }
    cout<<d;
    return 0;
}