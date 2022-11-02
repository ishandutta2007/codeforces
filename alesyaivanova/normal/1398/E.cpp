#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int sum = 0, sum1 = 0, cnt = 0;
    set<int> a;
    set<int> b;
    auto pt1 = a.end();
    auto pt2 = b.end();
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        sum += y;
        if (pt1 != a.end())
        {
            sum1 -= (*pt1);
            pt1++;
            cnt--;
        }
        if (pt2 != b.end())
        {
            sum1 -= (*pt2);
            pt2++;
            cnt--;
        }
        if (x == 0)
        {
            if (y > 0)
            {
                a.insert(y);
                if (pt1 != a.end() && y > (*pt1))
                {
                    cnt++;
                    sum1 += y;
                }
            }
            else
            {
                y *= -1;
                if (pt1 != a.end() && y >= (*pt1))
                {
                    cnt--;
                    sum1 -= y;
                }
                if (pt1 != a.end() && y == (*pt1))
                    pt1++;
                a.erase(y);
            }
        }
        else
        {
            if (y > 0)
            {
                b.insert(y);
                if (pt2 != b.end() && y > (*pt2))
                {
                    cnt++;
                    sum1 += y;
                }
            }
            else
            {
                y *= -1;
                if (pt2 != b.end() && y >= (*pt2))
                {
                    cnt--;
                    sum1 -= y;
                }
                if (pt2 != b.end() && y == (*pt2))
                    pt2++;
                b.erase(y);
            }
        }
        auto u = b.begin();
        if (u != b.end())
            u++;
        while (cnt < (int)b.size() && (pt1 != a.begin() || pt2 != u))
        {
            if (pt1 == a.begin())
            {
                pt2--;
                sum1 += (*pt2);
                cnt++;
            }
            else if (pt2 == u)
            {
                pt1--;
                sum1 += (*pt1);
                cnt++;
            }
            else
            {
                pt1--, pt2--;
                if ((*pt1) > (*pt2))
                {
                    pt2++;
                    sum1 += (*pt1);
                    cnt++;
                }
                else
                {
                    pt1++;
                    sum1 += (*pt2);
                    cnt++;
                }
            }
        }
        cout << sum + sum1 << "\n";
    }
}