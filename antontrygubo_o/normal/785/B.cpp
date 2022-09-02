#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    int matMax = 0;
    int matMin = 1000000000;
    int progMax = 0;
    int progMin = 1000000000;
    int a, b;
    for (int i = 0; i<n; i++)
    {
        cin>>a>>b;
        matMin = min(matMin, b);
        matMax = max(matMax, a);
    }
    int m;
    cin>>m;
    for (int i = 0; i<m; i++)
    {
        cin>>a>>b;
        progMin = min(progMin, b);
        progMax = max(progMax, a);
    }
    
    int ans = 0;
    ans = max(ans, matMax - progMin);
    ans = max(ans, progMax - matMin);
    cout<<ans;
    
}