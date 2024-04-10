#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

const int maxN = 200;
int n, m;
char g[maxN][maxN], gcopy[maxN][maxN];

bool isOk()
{
    if (n < 3) return false;
    
    vector<char> a;
    vector<int> b;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
            if (g[i][j] != g[i][0])
                return false;
        
        if (i == 0 || g[i][0] != g[i - 1][0])
        {
            a.push_back(g[i][0]);
            b.push_back(i);
        }
    }
    
    sort(all(a));
    bool ok = (a.size() == 3 && a[0] == 'B' && a[1] == 'G' && a[2] == 'R');
    
    if (!(b.size() == 3 && b[2] - b[1] == b[1] - b[0] && b[2] - b[1] == n - b[2]))
        ok = false;
    
    return ok;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            g[i][j] = s[j];
    }
    
    bool ok = isOk();
    
    memcpy(gcopy, g, sizeof(g));
    
    swap(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            g[i][j] = gcopy[j][i];
        
    if (isOk())
        ok = true;
    
    cout << (ok ? "YES" : "NO") << endl;
    
    return 0;
}