#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll a[100000];
bool b[1000000];

int main()
{
    ll n;
    cin >> n;
    for(ll i = 0; i < n - 1; i++)
    {
        cin >> a[i];
        b[a[i]] = true;
    }
    for(int i = 1; i <= n; i++)
        if(!b[i])
            cout << i;
}