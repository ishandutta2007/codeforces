#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;
const long long INF = 3ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
int n;
long long t;
long long a[MAX_N];
int x[MAX_N];
long long b[MAX_N];
vector<pair<int, int> > good;
int bad[MAX_N];
int used[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        x[i]--;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (x[i] > x[i + 1] || x[i] < i)
        {
            cout << "No";
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (x[i] != i)
        {
            good.emplace_back(i + 1, -1);
            good.emplace_back(x[i], 1);
        }
        bad[i] = x[i] + 1;
    }
    sort(good.begin(), good.end());
    sort(bad, bad + n);
    int j = 0;
    int bal = 0;
    for (int i = 0; i < n; i++)
        used[i] = 1;
    for (int i = 0; i < (int) good.size(); i++)
    {
        while (j < n && bad[j] < good[i].first || (bad[j] == good[i].first && good[i].second == 1))
        {
            if (bal)
            {
                cout << "No";
                return 0;
            }
            used[bad[j]] = 0;
            j++;
        }
        if (bal)
        {
            for (int e = good[i - 1].first; e <= good[i].first; e++)
                used[e] = 2;
        }
        bal -= good[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            b[i] = max(a[i] + t, b[i - 1] + 1);
        else
            b[i] = a[i] + t;
        if (i == n - 1)
            break;
        if (used[i + 1] == 0 && b[i] >= a[i + 1] + t)
        {
            cout << "No";
            return 0;
        }
        if (used[i + 1] == 2)
            b[i] = max(b[i], a[i + 1] + t);
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
}