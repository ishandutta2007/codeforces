#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 400005;

int n, k;
int a[N];
int hh[N];
int h[N];

int ans;
bool c[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        hh[i] = N;
    for (int i = n; i >= 1; --i)
    {
        h[i] = hh[a[i]];
        hh[a[i]] = i;
    }
    set<pair<int, int> > q;
    for (int i = 1; i <= n; ++i)
    {
        if (c[a[i]] == true)
        {
            q.erase(q.begin());
            q.insert(m_p(h[i], a[i]));
            continue;
        }
        if (q.size() >= k)
        {
            c[(--q.end())->second] = false;
            q.erase((--q.end()));
        }
        ++ans;
        c[a[i]] = true;
        q.insert(m_p(h[i], a[i]));
    }
    cout << ans << endl;
    return 0;
}