#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    vector<int> r[n];
    for(int i = 0; i < n; i++)
    {
        r[i].resize(5);
        for(int j = 0; j < 5; j++)
            cin >> r[i][j];
    }
    if(n > 100)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
            {
                if(i == j || j == k || k == i)
                    continue;
                int q = 0;
                for(int z = 0; z < 5; z++)
                    q += (r[j][z] - r[i][z]) * (r[k][z] - r[i][z]);
                if(q > 0)
                    goto nxt;
            }
        ans.push_back(i);
        nxt:;
    }
    cout << ans.size() << endl;
    for(auto it: ans)
        cout << it + 1 << ' ';
    return 0;
}