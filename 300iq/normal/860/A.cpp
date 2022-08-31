
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

bool vis[256];

bool bad(char a, char b, char c)
{
    if (vis[a] || vis[b] || vis[c]) return false;
    if (a == b && b == c && a == c) return false;
    return true;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    string s = "aueiou";
    for (auto c : s) vis[c] = true;
    cin >> s;
    int n = s.size();
    vector <int> dp(n + 1, 1e9);
    dp[0] = 0;
    vector <int> pr(n + 1);
    vector <bool> free(n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (j - 2 >= i && bad(s[j - 2], s[j - 1], s[j]))
            {
                if (dp[j] > dp[i] + 1)
                {
                    dp[j] = dp[i] + 1;
                    pr[j] = i;
                    free[j] = false;
                }
                break;
            }
            if (dp[j + 1] > dp[i] + 1)
            {
                dp[j + 1] = dp[i] + 1;
                pr[j + 1] = i;
            }
        }
    }
    int cur = n;
    vector <string> ans;
    while (cur != 0)
    {
        string p = "";
        for (int i = pr[cur]; i < cur; i++)
        {
            p += s[i];
        }
        ans.push_back(p);
        cur = pr[cur];
    }
    reverse(ans.begin(), ans.end());
    for (auto c : ans) cout << c << ' ';
    cout << endl;
}