#include <bits/stdc++.h>

using namespace std;

void fail()
{
    cout << -1 << "\n";
    exit(0);
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    vector<vector<int> > cycles[n + 1];
    int used[n];
    memset(used, 0, sizeof(used));
    for(int i = 0; i < n; i++)
    {
        vector<int> t;
        while(!used[i])
        {
            used[i] = 1;
            t.push_back(i);
            i = p[i];
        }
        cycles[t.size()].push_back(t);
    }
    for(int i = 2; i <= n; i += 2)
        if(cycles[i].size() % 2)
            fail();
    vector<vector<int> > c_ans[n + 1];
    for(int i = 2; i <= n; i += 2)
        for(int j = 0; j < cycles[i].size(); j += 2)
        {
            vector<int> t;
            for(int k = 0; k < i; k++)
            {
                t.push_back(cycles[i][j][k]);
                t.push_back(cycles[i][j + 1][k]);
            }
            c_ans[2 * i].push_back(t);
        }
    for(int i = 1; i <= n; i += 2)
        for(int j = 0; j < cycles[i].size(); j++)
        {
            vector<int> t(i);
            t[0] = cycles[i][j][0];
            for(int k = 1; k < i; k++)
                t[2 * k % i] = cycles[i][j][k];
            c_ans[i].push_back(t);
        }
    int q[n];
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < c_ans[i].size(); j++)
            for(int k = 0; k < i; k++)
                q[c_ans[i][j][k]] = 1 + c_ans[i][j][(k + 1) % i];
    for(int i = 0; i < n; i++)
        cout << q[i] << ' ';
    cout << "\n";
}