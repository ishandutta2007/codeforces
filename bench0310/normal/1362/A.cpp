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
        ll a,b;
        cin >> a >> b;
        int res=100;
        ll x=a;
        int c=0;
        while(x<b)
        {
            x*=2;
            c++;
        }
        if(x==b) res=min(res,c);
        x=a;
        c=0;
        while(x>b&&(x&1)==0)
        {
            x/=2;
            c++;
        }
        if(x==b) res=min(res,c);
        if(res!=100) cout << (res+2)/3 << "\n";
        else cout << "-1\n";
    }
    return 0;
}