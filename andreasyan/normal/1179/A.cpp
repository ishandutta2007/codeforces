#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n, qq;
int maxu = -1;
deque<int> q;

int k;
pair<int, int> ans[N];

vector<int> v;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> qq;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        maxu = max(maxu, x);
        q.push_back(x);
    }
    while (1)
    {
        int x = q.front();
        q.pop_front();
        int y = q.front();
        q.pop_front();
        q.push_front(max(x, y));
        q.push_back(min(x, y));
        ans[++k] = m_p(x, y);
        if (max(x, y) == maxu)
        {
            for (int i = 1; i < n; ++i)
                v.push_back(q[i]);
            break;
        }
    }
    while (qq--)
    {
        long long x;
        cin >> x;
        if (x <= k)
            cout << ans[x].first << ' ' << ans[x].second << endl;
        else
        {
            x -= k;
            --x;
            cout << maxu << ' ' << v[x % v.size()] << endl;
        }
    }
    return 0;
}