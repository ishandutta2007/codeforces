#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
string s;

int RA[500001];
int SA[500001];

int tmp[500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        RA[i] = s[i];
        SA[i] = i;
    }

    for (int k = 1; k < n; k *= 2)
    {
        auto cmp = [&k](int a, int b)
        {
            if (RA[a] != RA[b]) return RA[a] < RA[b];
            int a2 = RA[(a + k) % n];
            int b2 = RA[(b + k) % n];
            return a2 < b2;
        };

        sort(SA, SA + n, cmp);

        tmp[SA[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (!cmp(SA[i - 1], SA[i]) && !cmp(SA[i], SA[i - 1]))
                tmp[SA[i]] = tmp[SA[i - 1]];
            else
                tmp[SA[i]] = tmp[SA[i - 1]] + 1;
        }

        for (int i = 0; i < n; i++) RA[i] = tmp[i];
    }

    int res = n;
    for (int i = 1; i < n; i++)
    {
        if (RA[i] > RA[0])
        {
            res = i;
            break;
        }
    }

    for (int i = 0; i < k; i++)
        cout << s[i % res];
}