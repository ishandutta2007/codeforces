#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, T;
    vector<int> a[MAXN];
    int t[MAXN], q[MAXN];
    cin >> n >> T;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> q[i];
        a[t[i]].push_back(q[i]);
    }
    for (int i = 1; i < T; i++)
    {
        sort(a[i].begin(), a[i].end());
        int k = (int)a[i].size();
        for (int j = 0; j < k / 2; j++)
            a[i + 1].push_back(a[i][k - 1 - 2 * j] + a[i][k - 2 - 2 * j]);
        if (k % 2 == 1)
            a[i + 1].push_back(a[i][0]);
    }
    sort(a[T].begin(), a[T].end());
    int k = (int)a[T].size();
    cout << a[T][k - 1];
    return 0;
}