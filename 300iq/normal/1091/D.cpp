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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>

using namespace std;

typedef long long ll;

#ifdef ONPC
    mt19937 rnd(228);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int m = 998244353;

int add(int a, int b)
{
    a += b;
    if (a < 0) a += m;
    if (a >= m) a -= m;
    return a;
}

int mul(int a, int b)
{
    return (a * (ll) b) % m;
}

int bin(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = (a * (ll) a) % m;
            n /= 2;
        }
        else
        {
            res = (res * (ll) a) % m;
            n--;
        }
    }
    return res;
}

int inv(int x)
{
    return bin(x, m - 2);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> fact(n + 1);
    vector <int> rfact(n + 1);
    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * (ll) i) % m;
        rfact[i] = inv(fact[i]);
    }
    int ans = fact[n];
    int sum = 0;
    for (int i = 1; i < n; i++) 
    {
        sum = add(sum, rfact[i]);
    }
    cout << mul(ans, add(n, -sum)) << endl;
}