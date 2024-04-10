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
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (!s.empty() && s.back() != c && s.back() != '*')
        {
            s.back() = '*';
        }
        else
        {
            s += c;
        }
    }
    cout << s.size() << '\n';
}