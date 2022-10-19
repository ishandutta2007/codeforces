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
const int N = 1003;

int n;
int d1[N], d2[N];

bool stg(int D)
{
    multiset<int> s1, s2;
    for (int i = 1; i <= n; ++i)
    {
        s1.insert(d1[i]);
        s2.insert(d2[i]);
    }
    vector<int> ans;
    while (1)
    {
        if (s1.empty())
        {
            int p1 = 0, p2 = D;
            int minu = 0;
            for (int i = 0; i < n; ++i)
                minu = min(minu, ans[i]);
            for (int i = 0; i < n; ++i)
                ans[i] -= minu;
            p1 -= minu;
            p2 -= minu;
            cout << "YES\n";
            for (int i = 0; i < n; ++i)
                cout << ans[i] << ' ';
            cout << "\n";
            cout << p1 << ' ' << p2 << "\n";
            return true;
        }
        int m1 = *(--s1.end());
        int m2 = *(--s2.end());
        if (max(m1, m2) > D)
        {
            if (m1 > m2)
            {
                s1.erase(s1.find(m1));
                if (s2.find(m1 - D) == s2.end())
                    return false;
                s2.erase(s2.find(m1 - D));
                ans.push_back(m1);
            }
            else
            {
                s2.erase(s2.find(m2));
                if (s1.find(m2 - D) == s1.end())
                    return false;
                s1.erase(s1.find(m2 - D));
                ans.push_back(D - m2);
            }
        }
        else
        {
            for (auto it = s1.begin(); it != s1.end(); ++it)
            {
                int x = *it;
                if (s2.find(D - x) == s2.end())
                    return false;
                s2.erase(s2.find(D - x));
                ans.push_back(x);
            }
            int p1 = 0, p2 = D;
            int minu = 0;
            for (int i = 0; i < n; ++i)
                minu = min(minu, ans[i]);
            for (int i = 0; i < n; ++i)
                ans[i] -= minu;
            p1 -= minu;
            p2 -= minu;
            cout << "YES\n";
            for (int i = 0; i < n; ++i)
                cout << ans[i] << ' ';
            cout << "\n";
            cout << p1 << ' ' << p2 << "\n";
            return true;
        }
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d1[i];
    for (int i = 1; i <= n; ++i)
        cin >> d2[i];

    //sort(d1 + 1, d1 + n + 1);
    //sort(d2 + 1, d2 + n + 1);

    for (int i = 1; i <= n; ++i)
    {
        if (stg(d1[1] + d2[i]))
            return;
        if (stg(abs(d1[1] - d2[i])))
            return;
    }
    cout << "NO\n";
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