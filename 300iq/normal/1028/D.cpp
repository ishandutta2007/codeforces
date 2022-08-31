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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set <int> q;
    int mod = 1e9 + 7;
    ll res = 1;
    vector <pair <string, int> > f;
    map <int, int> type;
    set <int> buy;
    set <int> sell;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "ADD")
        {
            int x;
            cin >> x;
            f.push_back({s, x});
            if (!buy.empty() && x < *buy.rbegin())
            {
                buy.insert(x);
            }
            else if (!sell.empty() && x > *sell.begin())
            {
                sell.insert(x);
            }
            else
            {
                q.insert(x);
            }
        }
        else
        {
            int x;
            cin >> x;
            f.push_back({s, x});
            if (!buy.count(x) && !sell.count(x))
            {
                res *= 2;
                res %= mod;
            }
            if (!buy.empty() && *buy.rbegin() > x)
            {
                cout << 0 << '\n';
                return 0;
            }
            if (!sell.empty() && *sell.begin() < x)
            {
                cout << 0 << '\n';
                return 0;
            }
            for (int ret : q)
            {
                if (ret < x)
                {
                    buy.insert(ret);
                }
                else if (ret > x)
                {
                    sell.insert(ret);
                }
            }
            q.clear();
            if (buy.count(x)) buy.erase(x);
            if (sell.count(x)) sell.erase(x);
        }
        if (!buy.empty() && !sell.empty() && *buy.rbegin() > *sell.begin())
        {
            cout << 0 << '\n';
            return 0;
        }
    }
    if (!q.empty())
    {
        res *= ((int) q.size() + 1);
        res %= mod;
    }
    cout << res << '\n';
}