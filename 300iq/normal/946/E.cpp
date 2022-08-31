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
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = (int) s.size();
        string res = "";
        for (int i = 0; i < n - 2; i++)
        {
            res += '9';
        }
        for (int lcp = n - 1; lcp >= 0; lcp--)
        {
            if (s[lcp] != '0')
            {
                for (char c = s[lcp] - 1; c >= (lcp == 0 ? '1' : '0'); c--)
                {
                    string cur = s.substr(0, lcp) + c;
                    int mask = 0;
                    for (int i = 0; i < (int) cur.size(); i++)
                    {
                        mask ^= (1 << (cur[i] - '0'));
                    }
                    string me = "";
                    for (int i = 9; i >= 0; i--)
                    {
                        if ((mask >> i) & 1)
                        {
                            me += (i + '0');
                        }
                    }
                    while (cur.size() + me.size() < s.size())
                    {
                        cur += '9';
                    }
                    cur += me;
                    if (cur.size() == s.size())
                    {
                        res = cur;
                        break;
                    }
                }
                if (res.size() == s.size())
                {
                    break;
                }
            }
        }
        cout << res << '\n';
    }
}