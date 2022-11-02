#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[100000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    multiset<int> m;
    int num_loc = 0;
    int mink = 0;
    int q[n];
    for (int i = 0; i < n; i++)
        q[i] = -1;
    for (int i = 0; i < n; i++)
    {
        int pos = a[i].second;
        if ((pos == 0 || q[pos - 1] == -1) && (pos == n - 1 || q[pos + 1] == -1))
        {
            m.insert(1);
            q[pos] = pos;
        }
        else if (pos < n - 1 && pos > 0 && q[pos + 1] != -1 && q[pos - 1] != -1)
        {
            int k1 = pos - q[pos - 1];
            int k2 = q[pos + 1] - pos;
            m.erase(m.find(k1));
            m.erase(m.find(k2));
            int left = q[pos - 1];
            int right = q[pos + 1];
            q[left] = right;
            q[right] = left;
            m.insert(k1 + k2 + 1);
        }
        else if (pos < n - 1 && q[pos + 1] != -1)
        {
            q[pos] = q[pos + 1];
            q[q[pos + 1]] = pos;
            m.erase(m.find(q[pos] - pos));
            m.insert(q[pos] - pos + 1);
        }
        else if (pos > 0 && q[pos - 1] != -1)
        {
            q[pos] = q[pos - 1];
            q[q[pos - 1]] = pos;
            m.erase(m.find(pos - q[pos]));
            m.insert(pos - q[pos] + 1);
        }

        auto j1 = m.begin();
        auto j2 = m.end();
        j2--;
        if ((*j1) == (*j2))
        {
            if ((int)m.size() > num_loc)
            {
                num_loc = m.size();
                mink = a[i].first + 1;
            }
        }
    }
    cout << mink;
}