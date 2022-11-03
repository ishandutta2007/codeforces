#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".txt","r",stdin); freopen (name".txt","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
typedef long long ll;
typedef long double ld;
const int arr=500000;

vector<int> dp[arr];

signed main()
{
    int n;
    cin>>n;
    dp[0]={1};
    dp[1]={0,1};

    for (int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        reverse(dp[i].begin(),dp[i].end());
        dp[i].pb(0);
        reverse(dp[i].begin(),dp[i].end());
        for (int j=0;j<dp[i-2].size();j++)
        {
            dp[i][j]+=dp[i-2][j];
            dp[i][j]%=2;
        }
    }

    cout<<dp[n].size()-1<<'\n';
    for (auto i:dp[n])
        cout<<i<<' ';
    cout<<'\n';
    cout<<dp[n-1].size()-1<<'\n';
    for (auto i:dp[n-1])
        cout<<i<<' ';
}
/*
1
0 0 1
1 1
1 2
*/