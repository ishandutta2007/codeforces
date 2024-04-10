#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
int a[100000];
int l[100000], r[100000], d[100000];
int cnt[100001];
ll add[100001];
int nw;
ll nw1;

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> l[i] >> r[i] >> d[i], l[i]--, r[i]--;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        cnt[x]++;
        cnt[y + 1]--;
    }
    for(int i = 0; i < m; i++)
    {
        nw += cnt[i];
        int x = l[i], y = r[i];
        add[x] += 1LL * d[i] * nw;
        add[y + 1] -= 1LL * d[i] * nw;
    }
    for(int i = 0; i < n; i++)
    {
        nw1 += add[i];
        cout << nw1 + a[i] << ' ';
    }
}