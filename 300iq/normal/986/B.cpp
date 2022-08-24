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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e6 + 7;

int t[N];

void inc(int x, int y)
{
    for (; x < N; x = (x | (x + 1)))
    {
        t[x] += y;
    }
}

int get(int x)
{
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
    {
        ans += t[x];
    }
    return ans;
}

ll invs(vector <int> a)
{
    ll kek = 0;
    for (int x : a)
    {
        kek += get(N - 1) - get(x);
        inc(x, 1);
    }
    for (int x : a) inc(x, -1);
    return kek;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        b[i] = i;
    }
    int it = 3 * n;
    while (it--)
    {
        int x = rnd() % n;
        int y = rnd() % n;
        while (x == y) x = rnd() % n, y = rnd() % n;
        swap(b[x], b[y]);
    }
    ll val_1 = invs(b);
    it = 4 * n + 1;
    while (it--)
    {
        int x = rnd() % n;
        int y = rnd() % n;
        while (x == y) x = rnd() % n, y = rnd() % n;
        swap(b[x], b[y]);
    }
    ll val_2 = invs(b);
    ll val = invs(a);
    if (val % 2 == val_1 % 2)
    {
        cout << "Petr\n";
    }
    else
    {
        cout << "Um_nik\n";
    }
}