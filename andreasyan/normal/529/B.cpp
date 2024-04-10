#include <bits/stdc++.h>
using namespace std;
const int N = 1003, INF = 1000000009;
struct ban
{
    int w, h;
    ban()
    {
        w = h = 0;
    }
    ban(int w, int h)
    {
        this->w = w;
        this->h = h;
    }
};

int n;
ban a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].w >> a[i].h;
    int ans = INF;
    for (int i = 0; i < n; ++i)
    {
        int m = n / 2;
        int w = 0, h = a[i].h;
        vector<int> v;
        for (int j = 0; j < n; ++j)
        {
            if (a[j].h > h)
            {
                if (a[j].w > h)
                {
                    m = -1;
                }
                else
                {
                    --m;
                    w += a[j].h;
                }
            }
            else
            {
                w += a[j].w;
                if (a[j].w <= h && a[j].h < a[j].w)
                {
                    v.push_back(a[j].w - a[j].h);
                }
            }
        }
        if (m < 0)
            continue;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int j = 0; j < min((int)v.size(), m); ++j)
        {
            w -= v[j];
        }
        ans = min(ans, h * w);
    }
    for (int i = 0; i < n; ++i)
    {
        int m = n / 2;
        int w = 0, h = a[i].w;
        vector<int> v;
        for (int j = 0; j < n; ++j)
        {
            if (a[j].h > h)
            {
                if (a[j].w > h)
                {
                    m = -1;
                }
                else
                {
                    --m;
                    w += a[j].h;
                }
            }
            else
            {
                w += a[j].w;
                if (a[j].w <= h && a[j].h < a[j].w)
                {
                    v.push_back(a[j].w - a[j].h);
                }
            }
        }
        if (m < 0)
            continue;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int j = 0; j < min((int)v.size(), m); ++j)
        {
            w -= v[j];
        }
        ans = min(ans, h * w);
    }
    cout << ans << endl;
    return 0;
}