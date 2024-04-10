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


const int N = 1e6 + 20; 
const lli mod = 1e7 + 7;
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


int t, n, e;
bool pr[N];
int a[N];
lli ans;
int main()
{
    fastio;
    pr[0]=pr[1]=1;
    for (int i = 2; i < N; i++)
        if(!pr[i])
            for (lli j = (lli)i*1LL*(lli)i; j < N; j+=i) pr[j]=1;
    cin >> t;
    while (t--)
    {
        cin >> n >> e;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < e; j++)
        {
            vector<lli> fp, nax;
            lli nx = -1;
            int i1;
            for (int i = j; i < n; i+=e)
            {
                nax.ad(nx);
                if(a[i]==1) fp.ad(1);
                else if(pr[a[i]]==0) fp.ad(2), nx = fp.size()-1;
                else fp.ad(3), nx=fp.size()-1;
                i1 = i;
            }
            lli hj = fp.size();
            for (int i = fp.size()-1; i >= 0; i--)
            {
                if(fp[i]==1) continue;
                if(fp[i]==2)
                    ans+=(hj-i-1LL)+(i-nax[i]-1LL)+(hj-i-1LL)*1LL*(i-nax[i]-1LL);
                hj=i;
            }
        }
        cout<<ans<<"\n";
        ans=0;
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