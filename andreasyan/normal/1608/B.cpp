#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

void solv()
{
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b > n - 2)
    {
        cout << "-1\n";
        return;
    }
    if (abs(a - b) > 1)
    {
        cout << "-1\n";
        return;
    }

    if (a == b)
    {
        vector<int> ans;
        for (int i = 1; i <= a + 1; ++i)
        {
            ans.push_back(i);
            ans.push_back(n - i + 1);
        }
        ans.pop_back();
        int i = ans.back();
        while (sz(ans) != n)
        {
            ans.push_back(++i);
        }

        for (int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << "\n";
    }
    else if (a > b)
    {
        vector<int> ans;
        for (int i = 1; i <= a; ++i)
        {
            ans.push_back(i);
            ans.push_back(n - i + 1);
        }
        int i = ans.back();
        while (sz(ans) != n)
        {
            ans.push_back(--i);
        }

        for (int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << "\n";
    }
    else
    {
        swap(a, b);
        vector<int> ans;
        for (int i = 1; i <= a; ++i)
        {
            ans.push_back(i);
            ans.push_back(n - i + 1);
        }
        int i = ans.back();
        while (sz(ans) != n)
        {
            ans.push_back(--i);
        }
        for (int i = 0; i < n; ++i)
            ans[i] = n - ans[i] + 1;
        swap(a, b);

        for (int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}