#include <bits/stdc++.h>
using namespace std;
const int N = 1003, M = 20004;
struct ban
{
    int l, r;
};

int n;
ban a[N];

int s[M];

int dp[M];
int p[M];
int main()
{
    cin >> n;
    int minu = N * N;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].l >> a[i].r;
        if (a[i].r < a[i].l)
            swap(a[i].l, a[i].r);
        minu = min(minu, a[i].l);
    }
    for (int i = 0; i < M; ++i)
        s[i] = N * N;
    for (int i = 1; i <= n; ++i)
    {
        a[i].l -= minu;
        a[i].r -= minu;
        a[i].l++;
        a[i].r++;
        s[a[i].l] = min(s[a[i].l], a[i].r);
    }

    vector<int> v;
    for (int i = 0; i < M; ++i)
    {
        int k = s[i];
        for (int j = i; j <= k; ++j)
        {
            if (j == M)
                break;
            k = min(k, s[j]);
        }
        if (k != N * N)
            v.push_back(k + minu - 1);
        i = k;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << ' ';
    return 0;
}