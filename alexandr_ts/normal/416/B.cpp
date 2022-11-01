#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

typedef long long ll;
typedef long double ld;

int a[N][10];

vector <int> pos;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int m, n;
    int cur = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int t = 0;
    for (int i = 0; i < n; i++)
        pos.push_back(0);
    while (t < 250000001)
    {
        t++;
        for (int i = n - 1; i >= 0; i--)
            if (a[pos[i]][i] == 1 && (i == 0 || pos[i - 1] > pos[i]))
                 pos[i]++;
            else
                if (i == 0 || pos[i - 1] > pos[i])
                    a[pos[i]][i]--;
//        for (int i = 0; i < n; i++)
//            if (pos[i] > m)
//                pos[i] = m;
        if (pos[n - 1] > cur)
        {
            cout << t << endl;
            cur = pos[n - 1];
        }
        if (pos[n - 1] == m)
            break;
    }
}