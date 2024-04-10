#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int ans=n*2+m*2;
    ans=min(ans,n+m+k);
    ans=min(ans,n*2+k*2);
    ans=min(ans,m*2+k*2);
    
    cout << ans;
}