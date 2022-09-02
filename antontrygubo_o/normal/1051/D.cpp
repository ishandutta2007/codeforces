#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 998244353;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
        
    int n, k;
    cin>>n>>k;
    vector<vector<vector<ll>>> ans;
    for (int i = 0; i<=n; i++)
    {
        vector<vector<ll>> temp;
        for (int j = 0; j<=2*n; j++)
        {
            vector<ll> temp1(2, 0);
            temp.push_back(temp1);
        }
        ans.push_back(temp);
    }
    
    ans[1][1][1] = 1;
    ans[1][2][0] = 1;
    
    for (int i = 2; i<=n; i++)
    {
        for (int j = 1; j<=2*i; j++)
        {
            ans[i][j][1] = (ans[i-1][j-1][1] + ans[i-1][j][1] + 2*ans[i-1][j][0])%N;
            ans[i][j][0] = 2*ans[i-1][j-1][1] + ans[i-1][j][0];
            if (j>=2) ans[i][j][0] += ans[i-1][j-2][0];
            ans[i][j][0]%=N;
        }
    }
    
    cout<<(2*(ans[n][k][0]+ans[n][k][1]))%N;
    
    

    
}