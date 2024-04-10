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
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int was = 0;
    //for (ll n = 1; n <= 30; n++)
    ll n;
    cin >> n;
    {
        ll j = 0;
        vector <int> ans(n + 1);
        for (ll i = n; i >= 0; i--)
        {
            while (i * i + (j + 1) * (j + 1) <= n * n)
            {
                j++;
            }
            ans[i] = j;
        }
        ll ret = 0;
        for (ll i = 0; i <= n; i++)
        {
            ll delta = 0;
            if (ans[i] != 0) delta = 2;
            else delta = 1;
            if (i != 0) delta *= 2;
            ret += delta;
            if (ans[ans[i]] != i)
            {
                ll x = ans[i], y = i;
                ll delta = 0;
                if (y != 0) delta = 2;
                else delta = 1;
                if (x != 0) delta *= 2;
                ret += delta;
            }
            /*
            if (ans[ans[i]] != i)
            {
                ret += 4;
            }
            else
            {
                ret += 2;
            }
            */
        }
        /*
            q.insert({i, j});
            q.insert({i,-j});
            q.insert({-i,j});
            q.insert({-i,-j});
            swap(i, j);
            q.insert({i, j});
            q.insert({i,-j});
            q.insert({-i,j});
            q.insert({-i,-j});
            swap(i, j);
            //(i, j)
            //(i,-j)
            //(-i,j)
            //(i,-j)
        }
        cout << q.size() - was << ' ' << n << '\n';
        was = q.size();
        */
        cout << ret << '\n';
    }
}