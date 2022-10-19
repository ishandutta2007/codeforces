#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n, k;
int a[N];

int ans;
vector<pair<int, int> > v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    multiset<int> s;
    int j = 1;
    s.insert(a[1]);
    for (int i = 1; i <= n; ++i)
    {
        while (1)
        {
            if (j == n)
                break;
            ++j;
            s.insert(a[j]);
            if (*(--s.end()) - *s.begin() > k)
            {
                s.erase(s.find(a[j]));
                --j;
                break;
            }
        }
        if ((j - i + 1) > ans)
        {
            ans = (j - i + 1);
            v.clear();
            v.push_back(m_p(i, j));
        }
        else if ((j - i + 1) == ans)
        {
            v.push_back(m_p(i, j));
        }
        s.erase(s.find(a[i]));
    }
    cout << ans << ' ' << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i].first << ' ' << v[i].second << endl;
    return 0;
}