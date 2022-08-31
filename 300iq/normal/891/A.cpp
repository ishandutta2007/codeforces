//MYCOP -> smieci
/*









*/

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int gcd(int a, int b)
{
    return __gcd(a, b);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    int cnt = 0;
    int x = a[0];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        x = gcd(x, a[i]);
        if (a[i] == 1) cnt++;
    }
    if (x != 1)
    {
        puts("-1");
        return 0;
    }
    if (cnt != 0)
    {
        printf("%d\n", n - cnt);
    }
    else
    {
        int len = n;
        for (int i = 0; i < n; i++)
        {
            int g = a[i];
            for (int j = i; j < n; j++)
            {
                g = gcd(g, a[j]);
                if (g == 1) len = min(len, j - i);
            }
        }
        printf("%d\n", n + len - 1);
    }
}