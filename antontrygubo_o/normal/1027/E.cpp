#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 998244353;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<vector<ll>> G;
    for (int i = 0; i<=n; i++)
    {
        vector<ll> temp(n+1);
        G.push_back(temp);
    }
    
    for (int i = 1; i<=n; i++)
    {
        G[0][i] = 0;
        G[i][0] = 2;
        G[i][1] = 2;
        for (int j = 2; j<=i; j++) G[i][j] = (2*G[i][j-1])%N;
        for (int j = i+1; j<=n; j++) {G[i][j] = (2*G[i][j-1]-G[i][j-i-1])%N; if (G[i][j]<0) G[i][j]+=N;}
    }
    ll summ = 0;
    for (int i = 1; i<=n; i++)
    for (int j = 1; j<=n; j++)
    if (i*j<k) {summ = summ+(G[i][n]-G[i-1][n])*(G[j][n]-G[j-1][n]); summ%=N; if (summ<0) summ+=N;}
    if (summ%2==0) cout<<summ/2;
    else cout<<(summ+N)/2;
    
}