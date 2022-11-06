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

const int maxN = 100011;

int n, i;
ll v[maxN], least[maxN], ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
        least[i] = max(v[i] + 1, least[i - 1]);
    }

    for (i = n; i > 0; i--) {
        /*if (v[i] == 0 || v[i] == least[i] - 1) {
            least[i - 1] = max(least[i - 1], least[i] - 1);
        } else {
            least[i - 1] = max(least[i], least[i - 1]);
        }*/

        least[i - 1] = max(least[i - 1], least[i] - 1);
    }

    for (i = 1; i <= n; i++) ans += least[i] - v[i] - 1;
    printf("%lld", ans);



    return 0;
}