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
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 200;

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
vii p;
int a[N];
int ask()
{
    cout << "? ";
    for(auto p1 : p) cout << p1 << " ";
    cout << endl;
    int sm;
    cin >> sm;
    return sm - 1;
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) p.ad(1);
    a[n-1]=n;
    for (int i = n; i > 0; i--)
    {
        p[n-1]=i;
        int i1 = ask();
        if(i1 != -1)
        {
            a[i1]=n;
            a[n-1]=n-i+1;
            p[n-1]=1;
            break;
        }
    }
    //cout << a[0] << endl;
    for (int i = 1; i < a[n-1]; i++)
    {
        for (int j = 0; j < n - 1; j++) p[j] = a[n-1]-i+1;
        int i1 = ask();
        a[i1]=i;
    }
    for (int i = 0; i < n; i++) p[i]=1;
    for (int i = a[n-1] + 1; i < n; i++)
    {
        p[n-1]=i-a[n-1]+1;
        int i1 = ask();
        a[i1]=i;
    }
    cout << "! ";
    for (itn i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    
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