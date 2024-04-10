#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(false);
using namespace std;

int main()
{
    IOS
    ll n;
    cin>>n;
    ll arr[n][n];
    vector<ll> rowsum(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            rowsum[i]+=arr[i][j];
        }
    }
    vector<ll> colsum(n,0);
    for(int c=0;c<n;c++)
    {
        for(int r=0;r<n;r++)
        {
            colsum[c]+=arr[r][c];
        }
    }
    ll count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(colsum[j]>rowsum[i])
            {
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}