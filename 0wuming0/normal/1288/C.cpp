#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1000000007;
ll c[2000][2000];
int main()
{
    for(int i=0;i<2000;i++)c[0][i]=c[i][i]=1;
    for(int i=2;i<2000;i++)for(int j=1;j<i;j++)c[j][i]=(c[j][i-1]+c[j-1][i-1])%mod;
    int n,m;
    cin>>n>>m;
    cout<<c[n-1][n+2*m-1]<<endl;
}