#include <bits/stdc++.h>

using namespace std;

long long solve1(int k)
{
    return 1ll * k * 9 + 1;
}

long long solve2(int k)
{
    if (k == 0)
        return 1;
    return (1ll * k * (k - 1) / 2) * 9 * 9 + 1ll * k * 9 + 1;
}

long long solve3(int k)
{
    if (k == 0)
        return 1;
    if (k == 1)
        return 10;
    if (k == 2)
        return 100;
    return (1ll * k * (k - 1) * (k - 2) / 6) * 9 * 9 * 9 + (1ll * k * (k - 1) / 2) * 9 * 9 + 1ll * k * 9 + 1;
}

long long solve(int k, vector<int>& a)
{
    int cnt = 0;
    long long ans = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        if (a[i] == 0)
            continue;
        cnt++;
        if (cnt == 1)
            ans += (a[i] - 1) * solve2(i) + solve3(i);
        else if (cnt == 2)
            ans += (a[i] - 1) * solve1(i) + solve2(i);
        else
            ans += (a[i] - 1) + solve1(i);

        if (cnt == 3)
            break;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long a1, b1;
        cin >> a1 >> b1;
        a1--;
        vector<int> a, b;
        int ka = 0, kb = 0;
        while (a1)
        {
            a.push_back(a1 % 10);
            a1 /= 10;
            ka++;
        }
        while (b1)
        {
            b.push_back(b1 % 10);
            b1 /= 10;
            kb++;
        }
        cout << solve(kb, b) - solve(ka, a) << "\n";
    }
}