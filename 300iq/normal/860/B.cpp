
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

const int N = 5670000 + 7;

int to[N][10];
int sz = 1;
int dp[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    map <string, int> cnt;
    int n;
    cin >> n;
    vector <string> f;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        f.push_back(s);
        set <int> q;
        for (int t = 0; t < 9; t++)
        {
            int v = 0;
            for (int d = t; d < 9; d++)
            {
                int c = s[d] - '0';
                if (!to[v][c])
                {
                    to[v][c] = sz++;
                }
                v = to[v][c];
                if (!q.count(v))
                {
                    q.insert(v);
                    dp[v]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        string s = f[i];
        int l = 0, r = (int) s.size() - 1;
        for (int t = 0; t < 9; t++)
        {
            int v = 0;
            string p = "";
            for (int d = t; d < 9; d++)
            {
                p += s[d];
                v = to[v][s[d] - '0'];
                if (dp[v] == 1)
                {
                    if (d - t + 1 < r - l + 1)
                    {
                        l = t, r = d;
                    }
                }
            }
        }
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }
}