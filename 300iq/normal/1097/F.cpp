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

#ifdef ONPC
    mt19937 rnd(228);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 7001;
const int M = 1e5;

bitset <N> dp[M];
bitset <N> prec[N];
bitset <N> ret[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            prec[j][i] = 1;
        }
    }
    for (int i = N - 1; i >= 1; i--)
    {
        ret[i][i] = 1;
        for (int j = i + i; j < N; j += i)
        {
            ret[i] ^= ret[j];
        }
    }
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, v;
            cin >> x >> v;
            x--;
            dp[x] = prec[v];
        }
        else if (t == 2)
        {
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--, z--;
            dp[x] = dp[y] ^ dp[z];
        }
        else if (t == 3)
        {
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--, z--;
            dp[x] = dp[y] & dp[z];
        }
        else
        {
            int x, v;
            cin >> x >> v;
            x--;
       //     for (int it = 0; it < 10; it++) cout << dp[x][it];
            //cout << '\n';
            cout << ((dp[x] & ret[v]).count() % 2);
        }
        /*
        for (int i = 0; i < n; i++)
        {
            for (int it = 1; it <= 10; it++)
            {
                if ((dp[i] & ret[it]).count() % 2) cout << it << ',';
            }
            cout << "; ";
        }
        cout << endl;
        */
    }
    cout << '\n';
}