#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

vector <int> an;

ll a[100000];
ll b[100000];

int main()
{
    ll n, maxx;
    ll tim, qua;
    ll ans = 0;
    cin >> n >> maxx;
    for(int i = 0; i < n; i++)
    {
        cin >> tim >> qua;
        a[tim] += qua;
    }
    for(int i = 0; i <= 10000; i++)
        if(b[i] + a[i] <= maxx)
            ans += b[i] + a[i];
        else
            if(b[i] >= maxx)
            {
                ans += maxx;
                b[i + 1] = a[i];
            }
            else
            {
                ans += maxx;
                b[i + 1] = a[i] + b[i] - maxx;
            }
    cout << ans;
    return 0;

}