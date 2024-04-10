#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef unsigned uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef long long lng;
typedef unsigned long long ulng;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<lng, lng> PLL;
typedef pair<ld, ld> PDD;
typedef pair<ld, int> PDI;
typedef pair<string, int> PSI;
#define y1 asdy1
#define y0 asdy0
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
const ld RATIO = 1.6180339887498948482045868343656;

#define TASKA "prob"

int m, k;
int a[1 << 17];
int got[1 << 17];
int react[1 << 17];

string ans;

void solve()
{
  int q=0;
  while(q<m-1 && !react[q])
    ++q;
  set<int> immune;
  for(int i=q;i<m-1;++i)
    if(got[i]!=-1)
      immune.insert(got[i]);
  int unknown=0;
  forn(i,q){
    if(got[i]==-1)
      ++unknown;
    else{
      assert(a[got[i]]>0);
      --a[got[i]];
    }
  }

  set<int> force;
  if(q<m-1){
    int mn=INF;
    forn(i,k){
      if(!immune.count(i) && a[i]<=unknown){
        mn=min(mn,a[i]);
        force.insert(i);
      }
    }
    assert(mn<=unknown);
    unknown-=mn;
  }

  for(int i=q;i<m-1;++i){
    if(got[i]==-1)
      ++unknown;
    else{
      assert(a[got[i]]>0);
      --a[got[i]];
    }
  }

  ans="";
  forn(i,k){
    ans+=(force.count(i)||a[i]<=unknown)?'Y':'N';
  }
}

bool input()
{
    if (!(cin >> m >> k))
        return false;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m - 1; ++i) {
        cin >> got[i] >> react[i];
        --got[i];
    }
    return true;
}

void output()
{
    cout << ans << '\n';
}

int main()
{
#ifdef __ASD__
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while (t-- && input()) {
        solve();
        output();
    }

    return 0;
}