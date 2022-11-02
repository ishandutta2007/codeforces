#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 509;
int a[MAX_N];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> v;
    vector<int> u;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 2)
        {
            v.push_back(i);
            a[i] -= 2;
            cnt += a[i];
        }
        else
            u.push_back(i);
    }
    if (v.empty())
    {
        cout << "NO";
        return 0;
    }
    a[v[0]]++;
    a[v.back()]++;
    cnt += 2;
    if (cnt < (int)u.size())
    {
        cout << "NO";
        return 0;
    }
    cout << "YES " << v.size() + min(2ll, (int)u.size()) - 1 << "\n" << n - 1 << "\n";
    for (int i = 1; i < (int)v.size(); i++)
        cout << v[i - 1] + 1 << " " << v[i] + 1 << "\n";
    if (u.size() >= 1)
        cout << u[0] + 1 << " " << v[0] + 1 << "\n";
    if (u.size() >= 2)
        cout << u[1] + 1 << " " << v.back() + 1 << "\n";
    a[v[0]]--;
    a[v.back()]--;
    int j = 2;
    for (int i = 0; i < (int)v.size(); i++)
    {
        while (j < (int)u.size() && a[v[i]] >= 1)
        {
            cout << u[j] + 1 << " " << v[i] + 1 << "\n";
            a[v[i]]--;
            j++;
        }
    }
}