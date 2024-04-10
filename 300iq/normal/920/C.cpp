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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    string s;
    cin >> s;
    int last = -1;
    s += '0';
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (last == -1)
                last = i;
        }
        else
        {
            if (last != -1)
            {
                sort(a.begin() + last, a.begin() + i + 1);
            }
            last = -1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}