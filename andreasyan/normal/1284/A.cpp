#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 22;

int n, m;
string a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        --x;
        cout << a[x % n] + b[x % m] << endl;
    }
    return 0;
}