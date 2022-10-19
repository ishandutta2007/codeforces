#include <bits/stdc++.h>
using namespace std;
const int N = 20004;

int n;
int a[N];

int ans = -N * 1000;
void stg(int x)
{
    vector<int> v;
    int yans = 0;
    for (int i = 0; i < n; i += x)
    {
        v.push_back(i);
        yans += a[i];
    }
    while (1)
    {
        ans = max(ans, yans);
        if (v.back() == n - 1)
            break;
        for (int i = 0; i < v.size(); ++i)
        {
            yans -= a[v[i]];
            ++v[i];
            yans += a[v[i]];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        if (n % i == 0 && n / i >= 3)
            stg(i);
    }
    cout << ans << endl;
    return 0;
}