#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e3+5;
const int MOD=1e9+7;

int nCr[N][N];

void precompute()
{
    nCr[0][0]=1;
    for(int i=1;i<N;i++)
    {
        nCr[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            nCr[i][j]=nCr[i-1][j-1] + nCr[i-1][j];
            nCr[i][j]%=MOD;
        }
    }
}

int32_t main()
{ 
    IOS;
    precompute();
    int n, m, k;
    cin>>n>>m>>k;
    int ans=nCr[n-1][2*k] * nCr[m-1][2*k];
    ans%=MOD;
    cout<<ans;
    return 0;
}