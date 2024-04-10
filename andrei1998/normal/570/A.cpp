#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int a[105][105];
    int wins[105];

    cin >> m >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int w[105];
    for (int i = 1; i <= n; i++) {
        w[i] = 1;

        for (int j = 1; j <= m; j++) {
            if (a[i][j] > a[i][w[i]])
                w[i] = j;
        }

        wins[w[i]] ++;
    }

    vector <pair <int, int> > x;
    for (int i = 1; i <= n; i++)
        x.push_back(make_pair(-wins[w[i]], w[i]));

    sort(x.begin(), x.end());

    cout << x.front().second << endl;

    return 0;
}