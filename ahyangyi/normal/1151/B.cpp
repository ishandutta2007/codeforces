#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string polish(string english)
{
    if (english == "NO")
        return "NIE";
    return "TAK";
}

int main()
{
    std::ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> v[i][j];
        }
        total ^= v[i][0];
    }
    int tx = 0, ty = 0;
    if (total == 0)
    {
        for (int i = 0; total == 0 && i < n; ++i)
            for (int j = 1; total == 0 && j < m; ++j)
                if (v[i][j] != v[i][0])
                {
                    total = v[i][j] ^ v[i][0];
                    tx = i;
                    ty = j;
                }
    }
    if (total == 0)
    {
        cout << polish("NO") << endl;
    }
    else
    {
        cout << polish("YES") << endl;
        for (int i = 0; i < n; ++i)
        {
            if (i == tx)
            {
                cout << ty + 1;
            }
            else
            {
                cout << 1;
            }
            if (i + 1 < n)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }

    return 0;
}