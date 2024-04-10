#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        if(x[i] == 1) a.push_back(i);
        else b.push_back(i);
    }
    vector<pair<int, int>> ans;
    for(int t = 1; t <= n; t++)
    {
        int c = 0, d = 0;
        int pos = 0;
        bool l = 0;
        while(pos < n)
        {
            int i = lower_bound(a.begin(), a.end(), pos) - a.begin() - 1 + t;
            int j = lower_bound(b.begin(), b.end(), pos) - b.begin() - 1 + t;
            if(i >= a.size() && j >= b.size()) goto NXT;
            if(i >= a.size()) pos = b[j] + 1, d++, l = 1;
            else if(j >= b.size()) pos = a[i] + 1, c++, l = 0;
            else if(a[i] < b[j]) pos = a[i] + 1, c++, l = 0;
            else pos = b[j] + 1, d++, l = 1;
        }
        if((c > d && !l) || (c < d && l)) ans.push_back({max(c, d), t});
        NXT:;
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(auto it: ans) cout << it.first << ' ' << it.second << "\n";
    return 0;
}