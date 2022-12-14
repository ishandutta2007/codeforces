#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll dp[10000000];
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
   // freopen("half.in","r",stdin);
    //freopen("half.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    ll i,j;
    for(i=0;i<n;i++)cin >> dp[i];
    ll sc=0;
    for(i=0;i<n;i++)sc+=dp[i];
    double kk=n;
    ll dpp=sc/kk+0.5;
    j=0;
    while(dpp<m)
    {
        sc+=m;
        n++;
        j++;
        double kk=n;
        dpp=sc/kk+0.5;
    }
    cout << j << endl;
}