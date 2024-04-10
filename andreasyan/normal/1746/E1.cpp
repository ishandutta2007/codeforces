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

string qry(vector<int> v)
{
    cout << "? ";
    cout << sz(v) << ' ';
    for (int i = 0; i < sz(v); ++i)
        cout << v[i] << ' ';
    cout << endl;
    string ans;
    cin >> ans;
    return ans;
}

vector<int> p(vector<int> a, vector<int> b)
{
    for (int i = 0; i < sz(b); ++i)
        a.push_back(b[i]);
    return a;
}

void solv()
{
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    while (sz(v) >= 3)
    {
        vector<int> v1, v2, v3;
        for (int i = 0; i < sz(v) / 3; ++i)
            v1.push_back(v[i]);
        for (int i = sz(v) / 3; i < (sz(v) / 3) * 2; ++i)
            v2.push_back(v[i]);
        for (int i = (sz(v) / 3) * 2; i < (sz(v) / 3) * 3; ++i)
            v3.push_back(v[i]);
        if (sz(v) % 3 == 1)
            v3.push_back(v.back());
        else if (sz(v) % 3 == 2)
        {
            v2.push_back(v[sz(v) - 2]);
            v3.push_back(v.back());
        }

        if (qry(v1) == "YES")
        {
            if (qry(v2) == "YES")
                v = p(v1, v2);
            else
                v = p(v1, v3);
        }
        else
        {
            if (qry(v1) == "NO")
                v = p(v2, v3);
            else
            {
                if (qry(v2) == "YES")
                    v = p(v1, v2);
                else
                    v = p(v1, v3);
            }
        }
    }

    for (int i = 0; i < sz(v); ++i)
    {
        cout << "! " << v[i] << endl;
        string s;
        cin >> s;
        if (s == ":)")
            break;
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int n = 100000;
    int q = 0;
    while (n >= 3)
    {
        if (n % 3 == 2)
            n -= (n / 3 + 1);
        else
            n -= (n / 3);
        ++q;
    }
    cout << q << "\n";
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}