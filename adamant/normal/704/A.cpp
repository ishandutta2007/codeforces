#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> mes[n];
    vector<int> pos;
    int marked[q];
    fill(marked, marked + q, 0);
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < q; i++)
    {
        int t, p;
        cin >> t >> p;
        if(t == 1)
        {
            p--;
            pos.push_back(i);
            mes[p].push_back(i);
            ans++;
        }
        else if(t == 2)
        {
            p--;
            for(auto it: mes[p])
            {
                ans -= !marked[it];
                marked[it] = 1;
            }
            mes[p].clear();
        }
        else if(t == 3)
        {
            while(cur < p)
            {
                ans -= !marked[pos[cur]];
                marked[pos[cur]] = 1;
                cur++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}