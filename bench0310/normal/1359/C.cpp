#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while(z--)
    {
        ll h,c,t;
        cin >> h >> c >> t;
        if(2*t<=c+h) cout << "2\n";
        else
        {
            ll x=(h-t)/(2*t-h-c);
            if((h-c)*(2*x+2)+(4*x*x+8*x+3)*(h+c-2*t)<=0) cout << 2*x+1 << "\n";
            else cout << 2*(x+1)+1 << "\n";
        }
    }
    return 0;
}