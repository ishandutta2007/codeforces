
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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    vector <int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i] += '0';
    }
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (s[i] == '0');
        int cur = sum;
        ans = max(ans, sum);
        for (int j = i; j < n; j++)
        {
            cur += (s[j] == '1');
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
}