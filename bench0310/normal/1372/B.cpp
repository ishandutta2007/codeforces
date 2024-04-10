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
        int n;
        cin >> n;
        int d=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i) continue;
            d=max(d,i);
            if(i>1) d=max(d,n/i);
        }
        cout << d << " " << n-d << "\n";
    }
    return 0;
}