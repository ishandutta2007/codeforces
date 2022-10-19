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
const lli mod = 1e9 - 1;
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

int n;
void tp(int x, int n)
{
    for (int i = 0; i < x; i++) cout << "o";
    for (int i = 0; i < n - x; i++) cout << ".";
    cout << endl;
}
int main()
{
    fastio;
    cin >> n;
    if (n == 2) return cout << -1 << endl, 0;
    int sm = (int)sqrt(n);
    if ((sm + 1) * (sm + 1) == n + 2)
    {
        cout << sm + 2 << endl;
        tp(1, sm + 2);
        tp(sm - 1, sm + 2);
        tp(sm - 1, sm + 2);
        for (int i = 0; i < sm - 2; i++) tp(sm + 1, sm + 2);
        tp(sm + 2, sm + 2);
        return 0;
    }
    if (sm * sm == n)
    {
        cout << sm << endl;
        for (int i = 0; i < sm; i++) tp(sm, sm);
        return 0;
    }
    cout << sm + 1 << endl;
    int s = n - sm * sm + 1;
    tp(s / 2, sm + 1);
    if ((sm + 1) * (sm + 1) > n + 1) tp(sm - 1 + (s % 2), sm + 1);
    for (int i = 0; i < sm - 1 - s / 2; i++) tp(sm, sm + 1);
    for (int i = 0; i < s / 2; i++) tp(sm + 1, sm + 1);
    return 0;
}

/*
* 
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