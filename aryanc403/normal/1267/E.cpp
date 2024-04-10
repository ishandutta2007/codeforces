#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

vi a[100];
int sol = 1e9;
vector<pair<int, int>> vsol;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        vector<pair<int, int>> v;
        for (int j = 0; j < m; ++j)
            v.emplace_back(a[j][n - 1] - a[j][i], j);
            
        sort(all(v));
        int k = 0, sum = 0;
        while (k < m && sum + v[k].first <= 0)
        {
            sum += v[k].first;
            k++;
        }
        if (m - k < sol)
            sol = m - k, vsol = v;
    }
    cout << sol << '\n';
    for (int i = 1; i <= sol; ++i)
        cout << vsol[m - i].second + 1 << ' ';
}