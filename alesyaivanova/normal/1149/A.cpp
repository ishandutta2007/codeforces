#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 200009;
int a[MAXN];
int n;
int cnt[2];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i] - 1]++;
    }
    if (cnt[1])
    {
        cout << "2 ";
        cnt[1]--;
    }
    if (cnt[0])
    {
        cout << "1 ";
        cnt[0]--;
    }
    for (int i = 0; i < cnt[1]; i++)
        cout << "2 ";
    for (int i = 0; i < cnt[0]; i++)
        cout << "1 ";
}