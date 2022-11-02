#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define pf emplace_front
#define ff first
#define ss second
#define pii pair<int, int>
#define mp make_pair

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    if (k < 25)
    {
        cout << -1;
        return 0;
    }
    vector<char> m;
    m.pb('a');
    m.pb('o');
    m.pb('e');
    m.pb('u');
    m.pb('i');
    for (int i = 5; i * i <= k; i++)
    {
        if (k % i != 0)
            continue;
        if (k / i < 5)
            continue;
        int a = i;
        int b = k / i;
        for (int e = 0; e < a; e++)
        {
            for (int j = 0; j < b; j++)
                cout << m[(e + j) % 5];
        }
        return 0;
    }
    cout << -1;
}