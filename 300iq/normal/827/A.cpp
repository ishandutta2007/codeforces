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

const int N = 1e6 + 7;

string kek[N];
int val[N];
int l[N], r[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int q;
    cin >> q;
    vector <pair <pair <int, int>, int> > e;
    vector <pair <pair <int, int>, int> > f;
    int n = 0;
    int sz = 0;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        int lel = s.size();
        kek[i] = s;
        int k;
        cin >> k;
        while (k--)
        {
            int ind;
            cin >> ind;
            ind--;
            e.push_back({{ind, ind + lel - 1}, sz});
            f.push_back({{ind + lel - 1, ind}, sz});
            l[sz] = ind;
            val[sz] = i;
            n = max(n, ind + lel);
            sz++;
        }
    }
    sort(e.begin(), e.end());
    sort(f.begin(), f.end());
    int a = e.size();
    string res = "";
    int j = -1;
    int k = -1;
    multiset <int> s;
    for (int i = 0; i < n; i++)
    {
        while (j + 1 < a && e[j + 1].first.first <= i)
        {
            j++;
            s.insert(e[j].second);
        }
        if (!s.empty())
        {
            int ind = *s.begin();
            int kok = i - l[ind];
            res += (kek[val[ind]][kok]);
        }
        else
        {
            res += 'a';
        }
        while (k + 1 < a && f[k + 1].first.first <= i)
        {
            k++;
            s.erase(s.find(f[k].second));
        }
    }
    cout << res << '\n';
}