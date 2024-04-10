#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        if(n==1) cout << 0 << "\n";
        else if(n==2) cout << m << "\n";
        else cout << 2*m << "\n";
    }
    return 0;
}