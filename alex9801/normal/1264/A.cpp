#include <bits/stdc++.h>
using namespace std;

int arr[400010];

void solve()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    vector<pair<int, int>> v;
    int p = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == n - 1 || arr[i] != arr[i + 1])
        {
            v.push_back({ arr[i], i - p + 1 });
            p = i + 1;
        }
    }

    int sz = (int)v.size();
    if(sz <= 2 || v[0].second + v[1].second + v[2].second > n / 2)
    {
        puts("0 0 0");
        return;
    }

    int x = v[0].second;
    int s = 0;
    for(int i = 1; i < sz; i++)
    {
        s += v[i].second;
        if(s > x)
        {
            int s2 = 0;
            for(int j = i + 1; j < sz; j++)
            {
                s2 += v[j].second;
                if(s2 > x)
                {
                    int p = j + 1;
                    while(p < sz && x + s + s2 + v[p].second <= n / 2)
                    {
                        s2 += v[p].second;
                        p++;
                    }

                    if(x + s + s2 <= n / 2)
                        printf("%d %d %d\n", x, s, s2);
                    else
                        puts("0 0 0");

                    return;
                }
            }
        }
    }

    puts("0 0 0");
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, i;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();

    return 0;
}