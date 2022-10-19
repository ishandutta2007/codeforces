#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, k, d;

vector<vector<int> > vv;
int ans[N][N];
int main()
{
    cin >> n >> k >> d;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    vv.push_back(v);
    for (int ii = 1; ii <= d; ++ii)
    {
        vector<vector<int> > nvv;
        for (int jj = 0; jj < vv.size(); ++jj)
        {
            for (int s = 0; s < min((int)vv[jj].size(), k); ++s)
            {
                v.clear();
                for (int i = s; i < vv[jj].size(); i += k)
                {
                    int x = vv[jj][i];
                    ans[ii][x] = s + 1;
                    v.push_back(x);
                }
                nvv.push_back(v);
            }
        }
        vv = nvv;
    }
    if (vv.size() != n)
    {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 1; i <= d; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}