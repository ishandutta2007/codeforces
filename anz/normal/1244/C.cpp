#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, p, d, w, g;

set <pll> s;
queue <pll> q;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0), cout.tie(0);

   cin >> n >> p >> w >> d;
   if (n * w < p)
   {
      cout << -1;
      return 0;
   }

   g = gcd(w, d);
   if (p % g)
   {
      cout << -1;
      return 0;
   }

   ll x = n, y = 0;
   ll tmp = (n * w - p) / w;

   x -= tmp;

   s.insert({ x,y });
   q.push({ x,y });
   while (!q.empty())
   {
      auto tmp = q.front(); q.pop();
      ll cx = tmp.first;
      ll cy = tmp.second;

      ll res = cx * w + cy * d;
      if (res == p)
      {
         cout << cx << ' ' << cy << ' ' << n - cx - cy;
         return 0;
      }

      if (res < p)
      {
         if (cx + cy < n)
         {
            if (s.find({ cx + 1,cy }) == s.end())
            {
               s.insert({ cx + 1,cy });
               q.push({ cx + 1,cy });
            }
            if (s.find({ cx,cy + 1 }) == s.end())
            {
               s.insert({ cx,cy + 1 });
               q.push({ cx,cy + 1 });
            }
         }
      }
      else
      {
         if (cx > 0)
         {
            if (s.find({ cx - 1,cy }) == s.end())
            {
               s.insert({ cx - 1,cy });
               q.push({ cx - 1,cy });
            }
         }

         if (cy > 0)
         {
            if (s.find({ cx,cy - 1 }) == s.end())
            {
               s.insert({ cx,cy - 1 });
               q.push({ cx,cy - 1 });
            }
         }
      }
   }

   cout << -1;
}