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

using namespace std;

typedef long long ll;

mt19937 rnd(time(0));

int main()
{
    /*
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
*/
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll l = 1, r = n;
    int k;
    cin >> k;
    while (true)
    {
        while (r - l > 200) //iq
        {
            ll m = (l + r) / 2;
            cout << l << ' ' << m << endl;
            string s;
            cin >> s;
            if (s == "Yes")
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
            l = max(1ll, l - k);
            r = min(n, r + k);
        }
        vector <ll> cur;
        for (ll i = l; i <= r; i++) cur.push_back(i);
        int pos = rnd() % (int) cur.size();
        cout << cur[pos] << ' ' << cur[pos] << endl;
        string s;
        cin >> s;
        if (s == "Yes")
        {
            return 0;
        }
        else
        {
            l = max(1ll, l - k);
            r = min(n, r + k);
        }
    }
}