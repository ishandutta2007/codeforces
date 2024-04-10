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

const int MOD = 11;
const int N = 1e5 + 7;
const int A = 4;
const int KEK = 11;

char c[N];
int t[MOD][A][N][KEK];

int get_ind(char c)
{
    if (c == 'A')
    {
        return 0;
    }
    if (c == 'T')
    {
        return 1;
    }
    if (c == 'G')
    {
        return 2;
    }
    if (c == 'C')
    {
        return 3;
    }
    assert(0);
}

string get_str()
{
    scanf(" %s", c);
    return string(c);
}

void inc(int len, int symb, int pos, int mod, int y)
{
    for (; pos < N; pos = (pos | (pos + 1)))
    {
        t[len][symb][pos][mod] += y;
    }
}

int get(int len, int symb, int pos, int mod)
{
    int ans = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
    {
        ans += t[len][symb][pos][mod];
    }
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    string s = get_str();
    int n = s.size();
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = get_ind(s[i]);
    }
    for (int len = 1; len <= 10; len++)
    {
        for (int symb = 0; symb < 4; symb++)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == symb)
                {
                    inc(len, symb, i, i % len, 1);
                }
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x;
            char c;
            scanf("%d %c", &x, &c);
            x--;
            for (int len = 1; len <= 10; len++)
            {
                inc(len, a[x], x, x % len, -1);
            }
            a[x] = get_ind(c);
            for (int len = 1; len <= 10; len++)
            {
                inc(len, a[x], x, x % len, 1);
            }
        }
        else
        {
            int l, r;
            scanf("%d %d", &l, &r);
            l--, r--;
            string s = get_str();
            int len = s.size();
            int ans = 0;
            for (int i = 0; i < len; i++)
            {
                int c = get_ind(s[i]);
                int mod = (l + i) % len;
                ans += get(len, c, r, mod) - get(len, c, l - 1, mod);
            }
            printf("%d\n", ans);
        }
    }
}