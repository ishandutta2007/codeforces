
/*
      
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
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

mt19937 rnd(time(0));

pair <int, int> ask(int i)
{
    cout << "? " << i << endl;
    int val, next;
    cin >> val >> next;
    return {val, next};
}

void ans(int x)
{
    cout << "! " << x << endl;
    return;
}

int main()
{
    int n, start, x;
    cin >> n >> start >> x;
    vector <pair <int, int> > e;
    e.push_back(ask(start));
    int it = 1000;
    while (it--)
    {
        e.push_back(ask(rnd() % n + 1));
    }
    sort(e.begin(), e.end());
    if (e[0].first >= x)
    {
        ans(e[0].first);
        return 0;
    }
    int ind = -1;
    for (auto c : e)
    {
        if (c.first < x)
        {
            ind = c.second;
        }
    }
    while (ind != -1)
    {
        auto res = ask(ind);
        if (res.first >= x)
        {
            ans(res.first);
            return 0;
        }
        else
        {
            ind = res.second;
        }
    }
    ans(-1);
    return 0;
}