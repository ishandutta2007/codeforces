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

ll d, k, t, group, up, down, total;
ll ans;
ll over;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> k >> d >> t;
    t <<= 1;

    group = ((d + k - 1) / d) * d;
    up = k;
    down = group - up;
    total = 2 * up + down;

    ans += (t / total) * group;
    t %= total;

    if (2 * up >= t) {
        ans += t / 2;
        over = t % 2;
    } else {
        t -= 2LL * up;
        ans += up;
        ans += t;
    }

    cout << ans << '.' << over * 5;


    return 0;
}