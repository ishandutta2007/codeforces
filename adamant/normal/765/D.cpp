#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void fail()
{
    cout << -1 << endl;
    exit(0);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int f[n];
    map<int, vector<int>> rf;
    for(int i = 0; i < n; i++)
    {
        cin >> f[i];
        rf[f[i]].push_back(i + 1);
    }
    int sz = rf.size();
    int h[sz];
    int i = 0;
    for(auto it: rf)
        h[i++] = it.first;
    map<int, int> rh;
    for(int i = 0; i < sz; i++)
        rh[h[i]] = i + 1;
    int g[n];
    for(int i = 0; i < n; i++)
        g[i] = rh[f[i]];
    for(int i = 0; i < sz; i++)
        if(g[h[i] - 1] != i + 1)
            fail();
    for(int i = 0; i < n; i++)
        if(h[g[i] - 1] != f[i])
            fail();
    cout << sz << endl;
    for(int i = 0; i < n; i++)
        cout << g[i] << ' ';
    cout << endl;
    for(int i = 0; i < sz; i++)
        cout << h[i] << ' ';
    cout << endl;

}