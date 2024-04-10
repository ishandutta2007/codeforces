#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector <int> b(n);
    for (auto &c : b)
    {
        scanf("%d", &c);
    }
    int ans = -1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            multiset <int> f;
            for (int a = 0; a < i; a++)
            {
                f.insert(b[a]);
            }
            for (int a = j + 1; a < n; a++)
            {
                f.insert(b[a]);
            }
            multiset <int> s;
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += b[k];
                s.insert(b[k]);
            }
            int cur = k;
            while (1)
            {
                if (cur == 0 || s.size() == 0 || f.size() == 0 || *f.rbegin() < *s.begin())
                {
                    break;
                }
                int x = *s.begin();
                int t = *f.rbegin();
                sum -= x;
                sum += t;
                s.erase(s.find(x));
                s.insert(t);
                f.erase(f.find(t));
                f.insert(x);
                cur--;
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
}