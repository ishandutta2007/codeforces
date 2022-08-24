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
#include <bitset>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rnd(228);
 
int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, a, b;
    cin >> n;
    {
        int ans = 1e9;
        int x = 0, y = 0;
        for (int a = 1; a <= n; a++)
        {
            for (int b = max(1, n / a); a + b <= n + 1; b++)
            {
                if (a * (ll) b >= n)
                {
                    if (a + b < ans)
                    {
                        ans = a + b;
                        x = a, y = b;
                    }
                    break;
                }
            }
        }
        a = x, y = b;
    }
    bool rev = false;
    if (b < a)
    {
        swap(b, a);
        rev = true;
    }
    int l = 0, r = n + 1;
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        int ret = (n - m) / b + bool((n - m) % b);
        if (ret + m <= a)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    int x = l;
    n -= x;
    int init_n = n + x;
    vector <int> arr;
    vector <int> kek;
    for (int i = n; i < init_n; i++)
    {
        kek.push_back(i);
    }
    for (int i = 0; i < n; i += b)
    {
        int en = min(n - 1, i + b - 1);
        for (int j = en; j >= i; j--)
        {
            arr.push_back(j);
        }
    }
    if (!kek.empty()) for (int x : kek) arr.push_back(x);
    kek.clear();
    if (rev) reverse(arr.begin(), arr.end());
    for (int v : arr)
    {
        cout << v + 1 << ' ';
    }
    cout << '\n';
}