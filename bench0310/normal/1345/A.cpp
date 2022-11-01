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
        int n,m;
        cin >> n >> m;
        if(n==1||m==1||(n==2&&m==2)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}