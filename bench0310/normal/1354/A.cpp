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
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(b>=a) cout << b << "\n";
        else if(c-d>0) cout << b+((a-b+c-d-1)/(c-d))*c << "\n";
        else cout << "-1\n";
    }
    return 0;
}