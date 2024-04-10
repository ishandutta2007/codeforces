#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s, L;
    cin >> n >> s >> L;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> DP(n, INF);
    deque<int> mi, ma, minDP;
    int l = 0, r = 0;
    for(; r < n; r++)
    {
        while(mi.size() && a[r] < mi.back()) mi.pop_back();
        while(ma.size() && a[r] > ma.back()) ma.pop_back();
        if(r - L >= l - 1)
        {
            while(minDP.size() && DP[r - L] < minDP.back()) minDP.pop_back();
            minDP.push_back(DP[r - L]);
        }
        mi.push_back(a[r]); ma.push_back(a[r]);
        while(ma.front() - mi.front() > s)
        {
            if(a[l] == mi.front()) mi.pop_front();
            if(a[l] == ma.front()) ma.pop_front();
            if(!minDP.empty() && l && DP[l - 1] == minDP.front()) minDP.pop_front();
            l++;
        }
        if(r - l + 1 >= L)
        {
            if(l == 0) DP[r] = 1;
            else if(minDP.size())
            {
                int t = minDP.front();
                if(t != INF) DP[r] = t + 1;
            }
        }

    }
    if(DP[n - 1] == INF) cout << -1 << "\n";
    else cout << DP[n - 1] << "\n";
    return 0;
}