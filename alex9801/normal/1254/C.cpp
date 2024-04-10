#include <bits/stdc++.h>
using namespace std;

int n;
int qcnt = 0;
long long query(int t, int i, int j, int k)
{
    assert(qcnt < 3 * n);
    qcnt++;

    printf("%d %d %d %d\n", t, i, j, k);
    fflush(stdout);

    long long r;
    scanf("%lld", &r);
    return r;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    scanf("%d", &n);

    int x = 1;
    int y = 2;
    for(int i = 3; i <= n; i++)
        if(query(2, x, y, i) == -1)
            y = i;

    vector<pair<long long, int>> v;
    for(int i = 1; i <= n; i++)
    {
        if(i == x || i == y)
            continue;

        long long s = query(1, x, y, i);
        v.push_back({ s, i });
    }
    assert((int)v.size() == n - 2);

    sort(v.begin(), v.end());
    
    vector<int> res, res2;
    res.push_back(x);
    res.push_back(y);

    for(int i = 0; i < n - 2; i++)
    {
        int z = v[i].second;
        if(i + 1 < n - 2 && v[i].first == v[i + 1].first)
        {
            int w = v[i + 1].second;

            if(query(2, x, w, z) == -1)
                swap(z, w);

            res.push_back(w);
            res2.push_back(z);
            i++;
        }
        else
        {
            if(i == n - 3)
                res.push_back(z);
            else
            {
                int t = v[n - 3].second;

                if(query(2, x, t, z) == 1)
                    res2.push_back(z);
                else
                    res.push_back(z);
            }
        }
    }

    printf("0");
    for(int x : res)
        printf(" %d", x);
    
    reverse(res2.begin(), res2.end());
    for(int x : res2)
        printf(" %d", x);
    puts("");
    fflush(stdout);

    return 0;
}