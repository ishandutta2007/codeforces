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
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> s;
        string ans = s;

        int k = 1;
        for (int i = 1; i < n; i++)
        {
            string res = s.substr(i, n - i);
            string tmp = s.substr(0, i);
            if ((i + n) % 2) reverse(tmp.begin(), tmp.end());

            res += tmp;

            if (res < ans)
            {
                ans = res;
                k = i + 1;
            }
        }

        cout << ans << '\n';
        cout << k << '\n';
    }
}