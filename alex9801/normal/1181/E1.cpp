#include<bits/stdc++.h>
using namespace std;

struct str
{
    int a, b, c, d;
};

bool f(vector<str>& v)
{
    int n = (int)v.size();
    if(n <= 2)
        return 1;

    vector<tuple<int, int, int>> sor[2];
    for(int i = 0; i < n; i++)
    {
        auto [a, b, c, d] = v[i];
        sor[0].push_back({ a, c, i });
        sor[1].push_back({ b, d, i });
    }

    for(int i = 0; i < 2; i++)
    {
        sort(sor[i].begin(), sor[i].end());

        int mx = 0;
        for(int j = 0; j < n; j++)
        {
            auto [l, r, x] = sor[i][j];
            if(j != 0 && mx <= l)
            {
                vector<str> v1, v2;
                for(int k = 0; k < j; k++)
                    v1.push_back(v[get<2>(sor[i][k])]);
                for(int k = j; k < n; k++)
                    v2.push_back(v[get<2>(sor[i][k])]);

                return f(v1) && f(v2);
            }
            mx = max(mx, r);
        }
    }

    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<str> v;
    for(int i = 0; i < n; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        v.push_back({ a, b, c, d });
    }

    if(f(v))
        puts("YES");
    else
        puts("NO");

    return 0;
}