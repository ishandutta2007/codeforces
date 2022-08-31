#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

ll ind(int a, int b)
{
    return a * (ll) N + b;
}

vector <int> x[N], y[N];
unordered_set <ll> s;

int main()
{
    int ans = 0;
    int n;
    scanf("%d", &n);
    s.rehash(n);
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        s.insert(ind(a, b));
        if (x[a].size() < y[b].size())
        {
            for (auto d : x[a])
            {
                int x1 = a, y1 = b, x2 = a - abs(d - b), y2 = d;
                if (s.count(ind(x2, y1)) && s.count(ind(x2, y2)))
                {
                    ans++;
                }
                x1 = a, y1 = b, x2 = a + abs(d - b), y2 = d;
                if (s.count(ind(x2, y1)) && s.count(ind(x2, y2)))
                {
                    ans++;
                }
            }
        }
        else
        {
            for (auto d : y[b])
            {
                int x1 = a, y1 = b, x2 = d, y2 = b - abs(a - d);
                if (s.count(ind(x1, y2)) && s.count(ind(x2, y2)))
                {
                    ans++;
                }
                x1 = a, y1 = b, x2 = d, y2 = b + abs(a - d);
                if (s.count(ind(x1, y2)) && s.count(ind(x2, y2)))
                {
                    ans++;
                }
            }
        }
        x[a].push_back(b);
        y[b].push_back(a);
    }
    printf("%d\n", ans);
}