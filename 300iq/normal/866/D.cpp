
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

int ans;

void rec(int i, int have, const vector <int> &p, int res)
{
    if (i == (int) p.size())
    {
        if (have == 0)
        {
            ans = max(ans, res);
        }
    }
    else
    {
        for (int cur = 0; cur < 3; cur++)
        {
            if (cur == 0)
            {
                rec(i + 1, have, p, res);
            }
            else if (cur == 1)
            {
                rec(i + 1, have + 1, p, res - p[i]);
            }
            else if (have)
            {
                rec(i + 1, have - 1, p, res + p[i]);
            }
        }
    }
}

int solve_stupid(vector <int> p)
{
    ans = 0;
    rec(0, 0, p, 0);
    return ans;
}

ll solve_smart(vector <int> p)
{
    int n = p.size();
    vector <int> pr(n, -1);
    set <pair <int, int> > s;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!s.empty())
        {
            int delta = s.rbegin()->first;
            if (delta + p[i] > 0)
            {
                ans += delta + p[i];
                int j = s.rbegin()->second;
                if (pr[j] == -1)
                {
                    s.erase(--s.end());
                    s.insert({-p[j] - abs(p[i] - p[j]), j});
                    pr[j] = i, pr[i] = j;
                }
                else
                {
                    s.erase(--s.end()); 
                    int other = pr[j];
                    s.erase({-p[other] - abs(p[other] - p[j]), other});
                    s.insert({-p[other], other});
                    s.insert({-p[j] - abs(p[i] - p[j]), j});
                    pr[other] = -1;
                    pr[j] = i, pr[i] = j;
                }
            }
        }
        if (pr[i] != -1)
        {
            s.insert({-p[i] - abs(p[pr[i]] - p[i]), i});
        }
        else
        {
            s.insert({-p[i], i});
        }
    }
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector <int> p(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("%lld\n", solve_smart(p));
    /*
    while (true)
    {
        int n = 14;
        vector <int> p(n);
        vector <pair <int, int> > e;
        for (int i = 0; i < n; i++)
        {
            p[i] = rnd() % 10;
        }
        if (solve_smart(p) != solve_stupid(p))
        {
            cout << "WA" << endl;
            exit(0);
        }
        else
        {
            cout << "OK" << endl;
        }
    }
    */
    /*
    int n;
    scanf("%d", &n);
    vector <int> p(n), pr(n, -1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    set <pair <int, int> > s;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!s.empty())
        {
            int delta = s.rbegin()->first;
            if (delta + p[i] > 0)
            {
                ans += delta + p[i];
                int j = s.rbegin()->second;
                if (pr[j] == -1)
                {
                    s.erase(--s.end());
                    s.insert({-p[j] - abs(p[i] - p[j]), j});
                    pr[j] = i, pr[i] = j;
                }
                else
                {
                    s.erase(--s.end()); 
                    int other = pr[j];
                    s.erase({-p[other] - abs(p[other] - p[j]), other});
                    s.insert({-p[other], other});
                    pr[other] = -1;
                    pr[j] = i, pr[i] = j;
                }
            }
        }
        if (pr[i] != -1)
        {
            s.insert({-p[i] - abs(p[pr[i]] - p[i]), i});
        }
        else
        {
            s.insert({-p[i], i});
        }
    }
    printf("%lld\n", ans);
    */
}