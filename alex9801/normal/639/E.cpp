#include<bits/stdc++.h>
using namespace std;

struct str
{
    int p, t;
    bool operator <(const str& a) const
    {
        return 1LL * p * a.t > 1LL * a.p * t;
    }
};

str arr[150010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i].p);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i].t);

    sort(arr, arr + n);

    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i].t;

    long double s = 0, g = 1;
    for(int b = 0; b < 30; b++)
    {
        long double c = (s + g) / 2;

        vector<pair<int, long double>> v;
        long long cur = 0, t = 0;
        int p = 0;
        for(int i = 0; i < n; i++)
        {
            t += arr[i].t;
            if(i + 1 < n && 1LL * arr[i].p * arr[i + 1].t == 1LL * arr[i + 1].p * arr[i].t)
                continue;

            for(int j = p; j <= i; j++)
            {
                v.push_back({ arr[j].p, arr[j].p * (1 - c * (cur + arr[j].t) / sum) });
                v.push_back({ arr[j].p, arr[j].p * (1 - c * (cur + t) / sum) });
            }

            cur += t;
            t = 0;
            p = i + 1;
        }

        sort(v.begin(), v.end());

        bool ok = 1;
        long double mx = 0;
        for(int i = 0; i < (int)v.size(); i++)
        {
            if(v[i].second + 1e-9 < mx)
            {
                ok = 0;
                break;
            }

            mx = max(mx, v[i].second);
        }

        if(ok)
            s = c;
        else
            g = c;
    }

    printf("%.20Lf\n", (s + g) / 2);
    return 0;
}