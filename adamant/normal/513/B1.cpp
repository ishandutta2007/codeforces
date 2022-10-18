#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++)
        x[i] = i + 1;
    int ma = 0;
    vector<vector<int>> lol;
    do
    {
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            int t = n + 1;
            for(int j = i; j < n; j++)
            {
                t = min(t, x[j]);
                c += t;
            }
        }
        ma = max(c, ma);
    }
    while(next_permutation(x.begin(), x.end()));
    do
    {
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            int t = n + 1;
            for(int j = i; j < n; j++)
            {
                t = min(t, x[j]);
                c += t;
            }
        }
        if(c == ma)
            lol.push_back(x);
    }
    while(next_permutation(x.begin(), x.end()));
    sort(lol.begin(), lol.end());
    for(int i = 0; i < n; i++)
        cout << lol[m - 1][i] << ' ';
    return 0;
}