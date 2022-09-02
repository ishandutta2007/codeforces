#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;


int main()
{
ios_base::sync_with_stdio(false);

int n;
cin>>n;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];
vector<vector<ll>> DP0;
vector<vector<ll>> DP1;
vector<vector<ll>> DP2;
int k = (n+1)/2;

for (int i = 0; i<n; i++)
{
    vector<ll> temp(k+1, MAX);
    DP0.push_back(temp);
    DP1.push_back(temp);
    DP2.push_back(temp);
}

DP0[0][1] = 0;
for (int i = 1; i<n; i++)
{
    DP0[i][1] = max(a[i-1]+1-a[i], 0);
}
for (int i = 0; i<n; i++)
{
    DP0[i][0] = 0;
    DP1[i][0] = 0;
    DP2[i][0] = 0;
}

for (int i = 1; i<n; i++)
{
    for (int j = 1; j<=k; j++)
    {
        DP2[i][j] = min(DP2[i-1][j], DP1[i-1][j]);
        DP1[i][j] = DP0[i-1][j]+max(a[i]+1-a[i-1], 0);
        if (j>1)
        {DP0[i][j] = DP2[i-1][j-1]+max(a[i-1]+1-a[i], 0);
        if (i>1)
        {
            int c = min(a[i-1], a[i-2]-1);
            DP0[i][j] = min(DP0[i][j], DP1[i-1][j-1]+max(c+1-a[i], 0));
        }}
    }
}

for (int i = 1; i<=k; i++) cout<<min(min(DP0[n-1][i], DP1[n-1][i]), DP2[n-1][i])<<' ';
/*cout<<endl;
for (int i = 0; i<n; i++)
{for (int j = 0; j<=k; j++) cout<<DP0[i][j]<<' ';
cout<<endl;}
cout<<endl;

for (int i = 0; i<n; i++)
{for (int j = 0; j<=k; j++) cout<<DP1[i][j]<<' ';
cout<<endl;}
cout<<endl;

for (int i = 0; i<n; i++)
{for (int j = 0; j<=k; j++) cout<<DP2[i][j]<<' ';
cout<<endl;}
cout<<endl;
*/
}