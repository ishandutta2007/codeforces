#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a,b,n,m;
        cin >> a >> b >> n >> m;
        if(min(a,b)>=m&&a+b>=n+m) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}