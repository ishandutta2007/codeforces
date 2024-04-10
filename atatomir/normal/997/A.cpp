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

const int maxN = 300011;

ll n, i, x, y, last, cnt, ans;
char s[maxN], c;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld\n", &n, &x, &y);
    scanf("%s", s + 1);
    for (i = 1; i <= n; i++) {
        c = s[i];
        if (c == '0') {
            last++;
        } else {
            if (last > 0) {
                cnt++;
                last = 0;
            }
        }
    }

    if (last > 0) cnt++;

    if (cnt == 0) {
        ans = 0;
    } else {
        ans = (cnt - 1) * min(x, y) + y;
    }

    printf("%lld", ans);



    return 0;
}