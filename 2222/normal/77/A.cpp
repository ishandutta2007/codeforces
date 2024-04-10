#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
#include <complex>
#ifdef MY_JUDGE
#include <windows.h>
#endif
using namespace std;

///////////////// macros and typedefs ///////////////////
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define _fill(a, x) memset((a), (x), sizeof((a)))
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define ppb pop_back
//#define x first
//#define y second
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;

/*
 */

const string H[] = {
   "Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"
};

int n;
bool g[7][7];
vi p;
ll x[3];

typedef pair<ll, ll> LLL;

void solution()
{
   cin >> n;
   rep(i, n) {
      string a, b;
      cin >> a;
      cin >> b;
      //if (b != "likes") throw 1;
      cin >> b;
      int p = find(H, H+7, a) - H;
      int q = find(H, H+7, b) - H;
      //if (p == 7 || q == 7) throw 1;
      g[p][q] = 1;
   }
   ll Diff = -1, Likes = -1;
   rep(i, 3) cin >> x[i];
   for (int i0 = 0; i0 <= 2; i0++)
   for (int i1 = 0; i1 <= 2; i1++)
   for (int i2 = 0; i2 <= 2; i2++)
   for (int i3 = 0; i3 <= 2; i3++)
   for (int i4 = 0; i4 <= 2; i4++)
   for (int i5 = 0; i5 <= 2; i5++)
   for (int i6 = 0; i6 <= 2; i6++) {
      vi gr[3];
      gr[i0].pb(0);
      gr[i1].pb(1);
      gr[i2].pb(2);
      gr[i3].pb(3);
      gr[i4].pb(4);
      gr[i5].pb(5);
      gr[i6].pb(6);
      if (gr[0].empty() || gr[1].empty() || gr[2].empty())
         continue;
      ll mini = -1, maxi = -1;
      int likes = 0;
      rep(i, 3) {
         ll exp = x[i]/l(gr[i]);
         rep(j, l(gr[i]))
            for (int k = 0; k < l(gr[i]); k++)
               likes += g[gr[i][j]][gr[i][k]];
         if (mini == -1 || mini > exp) mini = exp;
         if (maxi == -1 || maxi < exp) maxi = exp;
      }
      ll diff = maxi - mini;
      //if (diff < 0) 
      if (Diff == -1 || (diff < Diff) || (diff == Diff && likes > Likes))
         Diff = diff, Likes = likes;
   }
   cout << Diff << " " << Likes << endl;
}

int main()
{
#ifdef MY_JUDGE
   freopen("my.in", "rt", stdin);
   //freopen("my.out", "wt", stdout);
   int start = GetTickCount();
#endif
   solution();
#ifdef MY_JUDGE
   int finish = GetTickCount();
   cerr << "Time: " << finish - start << endl;
#endif
   return 0;
}