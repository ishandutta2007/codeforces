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

bool solve(int n, vector <int> a)
{
    int ch = -1;
    for (int i = 0; i < n; i++) if (a[i] != 0) ch = i;
    if (ch == -1) return true;
    int pos = max_element(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[pos] && a[(i - 1 + n) % n] != a[pos])
        {
            pos = i;
            break;
        }
    }
    {
        vector <int> b(n, -1);
        b[pos] = a[pos];
        vector <ll> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = b[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i] != -1)
            {
                vector <int> ret;
                for (int j = (i + 1) % n; ; j = (j + 1) % n)
                {
                    if (b[j] == -1)
                    {
                        ret.push_back(a[j]);
                    }
                    else
                    {
                        ret.push_back(b[j]);
                        break;
                    }
                }
                ll last = ret.back();
                for (int j = (int) ret.size() - 2; j >= 0; j--)
                {
                    if (j != 0)
                    {
                        last = ret[j] + last * (ret[j - 1] / last + 1);
                    }
                    else
                    {
                        last = ret[j] + last * (b[i] / last + 1);
                    }
                    ans[(i + 1 + j) % n] = last;
                }
            }
        }
        bool bad = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != ans[i] % ans[(i + 1) % n])
            {
                bad = true;
            }
        }
        if (!bad)
        {
            return true;
        }
    }
    return false;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    while (true)
    {
        int n = rnd() % 10 + 2;
        vector <int> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = 1 + rnd() % 1000;
        }
        vector <int> b(n);
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i] % a[(i + 1) % n];
        }
        if (!solve(n, b))
        {
            cout << n << '\n';
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << ' ';
            }
            cout << '\n';
            for (int i = 0; i < n; i++)
            {
                cout << b[i] << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
    return 0;
    */
    int n;
    cin >> n;
    vector <int> a(n);
    bool good = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0) good = true;
    }
    if (!good)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            cout << 1 << ' ';
        }
        cout << '\n';
        return 0;
    }
    int pos = max_element(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[pos] && a[(i - 1 + n) % n] != a[pos])
        {
            pos = i;
            break;
        }
    }
    vector <int> b(n, -1);
    b[pos] = a[pos];
    vector <ll> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = b[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            vector <int> ret;
            for (int j = (i + 1) % n; ; j = (j + 1) % n)
            {
                if (b[j] == -1)
                {
                    ret.push_back(a[j]);
                }
                else
                {
                    ret.push_back(b[j]);
                    break;
                }
            }
            ll last = ret.back();
            for (int j = (int) ret.size() - 2; j >= 0; j--)
            {
                if (j != 0)
                {
                    last = ret[j] + last * (ret[j - 1] / last + 1);
                }
                else
                {
                    last = ret[j] + last * (b[i] / last + 1);
                }
                ans[(i + 1 + j) % n] = last;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != ans[i] % ans[(i + 1) % n])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}