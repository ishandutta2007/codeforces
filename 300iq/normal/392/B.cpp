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

const int N = 50;

ll dp[N][3][3];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <vector <int> > t(3, vector <int> (3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> t[i][j];
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (i != 0 && x != y)
                {
                    dp[i][x][y] = 1e18;
                }
                else
                {
                    dp[i][x][y] = 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int it = 0; it < 10; it++)
        {
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (x != y)
                    {
                        int z = 3 - x - y;
                        dp[i][x][y] = min(dp[i - 1][x][z] + dp[i - 1][z][y] + t[x][y], dp[i - 1][x][y] + t[x][z] + dp[i - 1][y][x] + t[z][y] + dp[i - 1][x][y]);
                    }
                }
            }
        }
    }
    cout << dp[n][0][2] << '\n';
}