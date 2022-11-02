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

const int maxn = 2007;
int cnt_l[maxn];
int cnt_r[maxn];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
        cnt_l[i] = (i ? cnt_l[i - 1] : 0) + (s[i] == '(');
    for (int i = n - 1; i >= 0; i--)
        cnt_r[i] = cnt_r[i + 1] + (s[i] == ')');
    int ma = 0;
    for (int i = 0; i < n - 1; i++)
        ma = max(ma, min(cnt_l[i], cnt_r[i + 1]));
    if (ma == 0)
    {
        cout << 0;
        return 0;
    }
    cout << "1\n" << 2 * ma << "\n";
    for (int i = 0; i < n - 1; i++)
    {
        if (cnt_l[i] == ma && cnt_r[i + 1] == ma)
        {
            vector<int> ans;
            int u = 0;
            for (int e = 0; u < ma; e++)
            {
                if (s[e] == '(')
                {
                    cout << e + 1 << " ";
                    u++;
                }
            }
            u = 0;
            for (int e = i + 1; u < ma; e++)
            {
                if (s[e] == ')')
                {
                    cout << e + 1 << " ";
                    u++;
                }
            }
            return 0;
        }
    }
}