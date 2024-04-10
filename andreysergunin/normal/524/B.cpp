#include <bits/stdc++.h>

#define f first
#define s second

const int MAXN = 1e5;
const long long INF = 1e18;

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int w[MAXN], h[MAXN];
    for (int i = 0; i < n; i++)
        cin >> w[i] >> h[i];

    long long ans = INF;
    for (int i = 0; i < n; i++)
    {
        bool f = true;
        long long m = h[i];
        long long d = 0;
        for (int j = 0; j < n; j++)
        {
            if (max(w[j], h[j]) <= m)
                d += min(w[j], h[j]);
            else
                if (min(w[j], h[j]) <= m)
                    d += max(w[j], h[j]);
                else
                    f = false;
        }
        if (f)
            ans = min (ans, d * m);

        f = true;
        m = w[i];
        d = 0;
        for (int j = 0; j < n; j++)
        {
            if (max(w[j], h[j]) <= m)
                d += min(w[j], h[j]);
            else
                if (min(w[j], h[j]) <= m)
                    d += max(w[j], h[j]);
                else
                    f = false;
        }
        if (f)
            ans = min (ans, d * m);
    }
    cout << ans;

}