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
        int n,m,k;
        cin >> n >> m >> k;
        int x=min(n/k,m);
        cout << x-(m-x+k-2)/(k-1) << "\n";
    }
    return 0;
}