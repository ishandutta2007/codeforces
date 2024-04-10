
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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    if (n > 100)
    {
        cout << 0 << '\n';
        return 0;
    }
    vector <vector <int> > a;
    for (int i = 0; i < n; i++)
    {
        vector <int> e;
        int x;
        for (int it = 0; it < 5; it++)
        {
            scanf("%d", &x);
            e.push_back(x);
        }
        a.push_back(e);
    }
    double pi = acos(-1);
    vector <int> ans;
    for (int i = 0; i < n; i++)
    {
        bool bad = false;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && i != k && j != k)
                {
                    ll scal = 0;
                    ll len_a = 0;
                    ll len_b = 0;
                    for (int it = 0; it < 5; it++)
                    {
                        scal += (a[j][it] - a[i][it]) * (ll) (a[k][it] - a[i][it]);
                        len_a += (a[j][it] - a[i][it]) * (ll) (a[j][it] - a[i][it]);
                        len_b += (a[k][it] - a[i][it]) * (ll) (a[k][it] - a[i][it]);
                    }
                    double l_a = sqrt(len_a);
                    double l_b = sqrt(len_b);
                    double oreo = scal / (l_a * l_b);
                    double ang = acos(oreo) * 180.0 / pi;
                    if (ang < 90)
                    {
                        bad = true;
                    }
                }
            }
        }
        if (!bad)
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int c : ans) cout << c + 1 << ' ';
    cout << '\n';
}