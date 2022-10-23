#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define all(vr) vr.begin(),vr.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
const int N=1e3+10;
ll n,a[N][N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
    ll v=sqrt(a[1][2]*a[1][3]/a[2][3]);
    cout<<v<<" ";
    for (int i=2;i<=n;i++) cout<<a[1][i]/v<<" ";
    return 0;
}