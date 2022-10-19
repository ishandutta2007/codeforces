#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 102;

int n, k;
int a[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    pair<int, int> h = m_p(-1000000000, 1000000000);
    for (int i = 1; i <= n; ++i)
    {
        pair<int, int> h1 = m_p(max(1, a[i] - k), a[i] + k);
        if (h1.second < h.second)
            swap(h, h1);
        if (h.second < h1.first)
        {
            cout << -1 << endl;
            return;
        }
        if (h.first < h1.first)
        {
            h = m_p(h1.first, h.second);
        }
    }
    cout << h.second << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--)
    {
        solv();
    }
    return 0;
}