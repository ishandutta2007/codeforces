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

const int N = 2e5 + 7;

vector <int> g[N];

set <int> s;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end());
        s.insert(i);
    }
    vector <int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s.count(i))
        {
            queue <int> q;
            q.push(i);
            s.erase(i);
            int cnt = 0;
            while (!q.empty())
            {
                cnt++;
                int v = q.front();
                q.pop();
                auto it = s.begin();
                int ptr = -1;
                vector <int> del;
                while (it != s.end())
                {
                    while (ptr + 1 < (int) g[v].size() && g[v][ptr + 1] <= *it)
                    {
                        ptr++;
                    }
                    if (ptr != -1 && g[v][ptr] == *it)
                    {
                        it++;
                    }
                    else
                    {
                        del.push_back(*it);
                        it++;
                    }
                }
                for (int v : del)
                {
                    q.push(v);
                    s.erase(v);
                }
            }
            ans.push_back(cnt);
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int v : ans) cout << v << ' ';
    cout << '\n';
}