//Arayi
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#include <chrono>
#include <random>
#include <complex>

#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jigglypuff
#define ld long double
#define itn int
#define pir pair<int, int>
#define all(x) (x).begin(), (x).end()
#define str string
#define enl endl
#define en endl
#define cd complex<long double>
#define vcd vector<cd>
#define vii vector<int>
#define vlli vector<lli>
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x, ld y1, ld x2, ld y2)
{
    return sqrt((x - x2) * (x - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
    return (a * (a + 1LL)) / 2;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 1e6 + 30;
const lli mod = 1e17;
const ld pi = acos(-1);
const int T = 550;

lli bp(lli a, lli b = mod - 2LL)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1) ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
ostream& operator<<(ostream& c, pir a)
{
    c << a.fr << " " << a.sc;
    return c;
}
template<class T>
void maxi(T& a, T b)
{
    a = max(a, b);
}
template <class T>
void mini(T& a, T b)
{
    a = min(a, b);
}


int n, q;
int a[N];
vii fp[N];
int sm(int x, int l, int r)
{
    int r1 = upper_bound(all(fp[x]), r) - fp[x].begin();
    int l1 = upper_bound(all(fp[x]), l - 1) - fp[x].begin();
    return r1-l1;
}
bool stg(int x, int s)
{
    return x <= (s+1)/2;
}
int main()
{
    fastio;
    cin>>n>>q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        fp[a[i]].ad(i);
    }
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        l--, r--;
        int mx = 0, n1 = r - l + 1;
        for (int i = 0; i < 50; i++)
        {
            int i1 = rnd()%n1;
            maxi(mx, sm(a[i1 + l], l, r));
        }
        if(stg(mx, n1)) cout<<1<<endl;
        else
        {
            int x = 2*mx - n1 - 1;
            while(!stg(mx - x, n1 - x)) x++;
            cout<<x+1<<endl;
        }
    }
    return 0;
}

/*

    __
  *(><)*
    \/ /
    ||/
  --||
    ||
    /\
   /  \
  /    \

*/