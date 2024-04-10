#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
    return a ? gcd(b % a, a) : b;
}

long long arr[510];
const long long mod = 998244353;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, i, j, k;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    map<long long, int> m;
    vector<long long> v;
    for(i = 0; i < n; i++)
    {
        bool ok = 0;
        for(j = 4; j >= 2; j--)
        {
            long long t = pow(arr[i], 1.0 / j);
            for(long long d = t - 10; d <= t + 10; d++)
            {
                if(d <= 1 || d >= arr[i])
                    continue;

                long long t2 = 1;
                for(k = 0; k < j; k++)
                    t2 *= d;

                if(t2 == arr[i])
                {
                    ok = 1;
                    m[d] += j;
                    break;
                }
            }
            if(ok)
                break;
        }
        if(!ok)
            v.push_back(arr[i]);
    }

    int sz = v.size();
    for(i = 0; i < sz; i++)
    {
        for(j = i + 1; j < sz; j++)
        {
            if(v[i] == v[j] || v[i] == 0 || v[j] == 0)
                continue;

            long long g = gcd(v[i], v[j]);
            if(g > 1)
            {
                m[g] += 2;
                m[v[i] / g]++;
                m[v[j] / g]++;

                v[i] = v[j] = 0;
            }
        }
    }

    vector<long long> v2;
    for(long long x : v)
    {
        if(x == 0)
            continue;

        bool ok = 0;
        long long t = 0;
        for(auto a : m)
        {
            long long p = a.first;

            if(x % p == 0)
            {
                ok = 1;
                t = p;
                break;
            }
        }

        if(ok)
        {
            m[t]++;
            m[x / t]++;
        }
        else
            v2.push_back(x);
    }

    long long res = 1;
    for(auto a : m)
        res = res * (a.second + 1) % mod;

    sort(v2.begin(), v2.end());

    sz = v2.size();
    int f = 0;
    for(i = 0; i < sz; i++)
    {
        if(i == sz - 1 || v2[i] != v2[i + 1])
        {
            int c = i - f + 1;
            res = res * (c + 1) % mod;
            res = res * (c + 1) % mod;
            f = i + 1;
        }
    }

    printf("%lld\n", res);
    fflush(stdout);
    return 0;
}