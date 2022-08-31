
/*
    !  !!!
   
   
   
   
   
   
   
   
   
   
   
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

map <set <int>, int> ans;

int res(set <int> &cur)
{
    if (ans.count(cur)) return ans[cur];
    set <int> mx;
    int px = *cur.rbegin();
    for (int x = 1; x <= px; x++)
    {
        set <int> other;
        for (auto d : cur)
        {
            if (d < x)
            {
                other.insert(d);
            }
            else
            {
                other.insert(d - x);
            }
        }
        mx.insert(res(other));
    }
    int f = 0;
    while (mx.count(f)) f++;
    ans[cur] = f;
    return f;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    map <int, set <int> > p;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                int cnt = 0;
                while (x % j == 0)
                {
                    cnt++;
                    x /= j;
                }
                p[j].insert(cnt);
            }
        }
        if (x != 1) p[x].insert(1);
    }
    for (auto c : p)
    {
        ans ^= res(c.second);
    }
    cout << (!ans ? "Arpa" : "Mojtaba") << '\n';
}