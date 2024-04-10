#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[200001];

vector <ll> prime;
vector <ll> big;

set <ll> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    prime.push_back(2);
    for (ll i = 3; i < 1000000; i++)
    {
        bool flag = true;
        for (auto p : prime)
        {
            if (p * p > i) break;
            if (i % p == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            prime.push_back(i);
        }
    }

    cin >> n;
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2) ans++;
    }

    for (int k = 0; k < 20; k++)
    {
        int idx = rng() % n;
        for (ll d = -1; d <= 1; d++)
        {
            ll cn = a[idx] + d;
            if (cn <= 2) continue;

            for (auto p : prime)
            {
                if (cn % p == 0)
                {
                    st.insert(p);
                    while (cn % p == 0) cn /= p;
                }
            }

            if (cn > 1) st.insert(cn);
        }
    }

    for (auto p : st)
    {
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < p)
            {
                res += p - a[i];
                continue;
            }

            ll tmp1 = a[i] % p;
            ll tmp2 = p - tmp1;
            res += min(tmp1, tmp2);
        }
        ans = min(ans, res);
    }

    cout << ans;
}