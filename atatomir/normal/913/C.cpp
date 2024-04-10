#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 43

ll n, i, L;
ll c[maxN], ans;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> L;
    for (i = 0; i < n; i++) cin >> c[i];
    for (i = n; i <= 30; i++) c[i] = (1LL << 60) + 11LL;

    for (i = 0; i <= 30; i++) c[i + 1] = min(c[i + 1], 2LL * c[i]);
    for (i = 0; i <= 30; i++, L >>= 1) {
        ans = min(ans, c[i]);
        if (L & 1) {
            ans += c[i];
        }
    }

    cout << ans;


    return 0;
}