#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
char a[N];
int m;
char bb[N];
char* b[N];

int z;
int t[N * 80];
map<char, int> h[N * 80];

bool dp[N];
int p[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> bb;
        b[i] = new char[strlen(bb) + 1];
        strcpy(b[i], bb);
        int pos = 0;
        for (int j = 0; b[i][j]; ++j)
        {
            char c = tolower(b[i][j]);
            if (h[pos].find(c) == h[pos].end())
                h[pos][c] = ++z;
            pos = h[pos][c];
        }
        t[pos] = i;
    }

    dp[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        int pos = 0;
        for (int j = i; j >= 1; --j)
        {
            if (h[pos].find(a[j]) == h[pos].end())
                break;
            pos = h[pos][a[j]];
            if (t[pos] && dp[j - 1])
            {
                dp[i] = true;
                p[i] = t[pos];
                break;
            }
        }
    }

    vector<int> v;
    int i = n;
    while (i)
    {
        v.push_back(p[i]);
        i = i - strlen(b[p[i]]);
    }

    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
        cout << b[v[i]] << ' ';
    cout << endl;
    return 0;
}