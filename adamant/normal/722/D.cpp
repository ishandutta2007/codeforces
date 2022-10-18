#include<bits/stdc++.h>

using namespace std;

map<int, int> hshr, rr;
int hsh(int x)
{
    if(hshr[x] == 0)
    {
        hshr[x] = hshr.size();
        rr[hshr[x]] = x;
    }
    assert(hshr[x] != 0);
    return hshr[x];
}

int rhsh(int x)
{
    return rr[x];
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int y[n];
    for(int i = 0; i < n; i++)
        cin >> y[i];
    sort(y, y + n);
    vector<int> X[n], ori[n];
    for(int i = 0; i < n; i++)
    {
        int t = y[i];
        while(y[i])
        {
            X[i].push_back(hsh(y[i]));
            ori[i].push_back(y[i]);
            y[i] /= 2;
        }
    }
    int sz = hshr.size();
    int l = 0, r = 1e9 + 7;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        int used[sz + 1];
        fill(used, used + sz + 1, 0);
        bool ok = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < X[i].size(); j++)
                if(!used[X[i][j]] && ori[i][j] <= m)
                {
                    used[X[i][j]] = 1;
                    goto nxt;
                }
            ok = 0;
            nxt:;
        }
        if(ok)
            r = m;
        else
            l = m;
    }
    int m = r;
        int used[sz + 1];
        fill(used, used + sz + 1, 0);
        bool ok = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < X[i].size(); j++)
                if(!used[X[i][j]] && ori[i][j] <= m)
                {
                    used[X[i][j]] = 1;
                    cout << ori[i][j] << ' ';
                    goto nxt2;
                }
            ok = 0;
            nxt2:;
        }
    return 0;
}