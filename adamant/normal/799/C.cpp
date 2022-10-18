#include <bits/stdc++.h>

using namespace std;


signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c[2];
    cin >> n >> c[0] >> c[1];
    int b[n], p[n];
    vector<int> lol[2];
    for(int i = 0; i < n; i++)
    {
        cin >> b[i] >> p[i];
        char t;
        cin >> t;
        lol[t == 'D'].push_back(i);
    }
    int ans = -1e9;
    for(int z = 0; z <= 1; z++)
    {
        int mx = -1e9;
        for(auto it: lol[!z])
            if(p[it] <= c[!z])
                mx = max(mx, b[it]);
        sort(begin(lol[z]), end(lol[z]), [&](int a, int b){return p[a] < p[b];});
        set<pair<int, int>> A, B;
        for(auto it: lol[z])
            A.insert({p[it], it}),
            B.insert({b[it], it});
        for(auto it: lol[z])
        {
            if(p[it] > c[z])
                break;
            ans = max(ans, b[it] + mx);
            while(A.size() && prev(end(A))->first + p[it] > c[z])
            {
                B.erase({b[prev(end(A))->second], prev(end(A))->second});
                A.erase(prev(end(A)));
            }
            A.erase({p[it], it});
            B.erase({b[it], it});
            if(B.size())
                ans = max(ans, b[it] + prev(end(B))->first);
            A.insert({p[it], it});
            B.insert({b[it], it});
        }
    }
    ans = max(ans, 0);
    cout << ans << endl;
}