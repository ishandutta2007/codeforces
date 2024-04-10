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
const int N = 200005;

map<pair<int, int>, pair<int, int> > mp;
map<int, int> stg;
pair<int, int> qry(int l, int r)
{
    if (mp.find(m_p(l, r)) != mp.end())
        return mp[m_p(l, r)];
    cout << "? " << l << ' ' << r << endl;
    int x, q;
    cin >> x >> q;
    stg[x]++;
    assert(stg[x] <= 3);
    return mp[m_p(l, r)] = m_p(x, q);
}

map<int, int> ans;
set<int> s;
void rec(int l, int r)
{
    if (l > r)
        return;

    int x = qry(l, r).fi;
    int q = qry(l, r).se;

    if (ans[x] != 0)
    {
        rec(l + q, r);
        ans[x] += q;
        return;
    }

    if (s.find(x) != s.end())
    {
        rec(l, r - q);
        ans[x] = q;
        return;
    }
    s.insert(x);

    for (int i = l; ; i += q)
    {
        rec(i, i + q - 1);
        if (ans[x] != 0)
        {
            rec(i + q + q - ans[x], r);
            ans[x] = q;
            return;
        }
    }
}

void solv()
{
    int n;
    cin >> n;
    rec(1, n);

    vector<int> v;
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        for (int i = 0; i < it->se; ++i)
            v.push_back(it->fi);
    }

    cout << "! ";
    for (int i = 0; i < sz(v); ++i)
        cout << v[i] << ' ';
    cout << endl;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}