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
const int N = 503;

int n, k;

bool z[N];
int qry(vector<int> v)
{
    cout << '?';
    for (int i = 0; i < sz(v); ++i)
        cout << ' ' << v[i];
    cout << endl;
    int ans = 0;
    cin >> ans;
    for (int i = 0; i < sz(v); ++i)
        z[v[i]] ^= true;
    return ans;
}

bool cc[N];
int rqry(vector<int> v)
{
    memset(cc, false, sizeof cc);
    for (int i = 0; i < sz(v); ++i)
        cc[v[i]] = true;
    cout << '?';
    for (int i = 1; i <= n; ++i)
    {
        if (!cc[i])
            cout << ' ' << i;
    }
    cout << endl;
    int ans = 0;
    cin >> ans;
    for (int i = 0; i < sz(v); ++i)
        z[v[i]] ^= true;
    return ans;
}

int solv()
{
    //cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        z[i] = false;

    if ((n % k) % 2 == 1 && k % 2 == 0)
    {
        cout << "-1" << endl;
        return -1;
    }

    if (n % k == 0)
    {
        int ans = 0;
        for (int i = 1; i <= n; i += k)
        {
            vector<int> v;
            for (int j = i; j < i + k; ++j)
                v.push_back(j);
            ans ^= qry(v);
        }
        cout << "! " << ans << endl;
        return n / k;
    }

    int ans = 0;
    for (int x = 1; x < k; ++x)
    {
        if (n >= 3 * k - 2 * x && (n - (3 * k - 2 * x)) % k == 0)
        {
            //cout << 3 + (n - (3 * k - 2 * x)) / k << "\n";
            vector<int> v;
            for (int i = 1; i <= x; ++i)
                v.push_back(i);
            int j = x + 1;
            for (int u = 0; u < k - x; ++u)
                v.push_back(j++);
            ans ^= qry(v);
            v.clear();
            for (int i = 1; i <= x; ++i)
                v.push_back(i);
            for (int u = 0; u < k - x; ++u)
                v.push_back(j++);
            ans ^= qry(v);
            v.clear();
            for (int i = 1; i <= x; ++i)
                v.push_back(i);
            for (int u = 0; u < k - x; ++u)
                v.push_back(j++);
            ans ^= qry(v);
            for (int i = 0; i < (n - (3 * k - 2 * x)) / k; ++i)
            {
                v.clear();
                for (int u = 0; u < k; ++u)
                    v.push_back(j++);
                ans ^= qry(v);
            }
            cout << "! " << ans << endl;
            return 3 + (n - (3 * k - 2 * x)) / k;
        }
    }

    k = n - k;
    for (int x = 1; x < k; ++x)
    {
        if (n >= 3 * k - 2 * x && (n - (3 * k - 2 * x)) % k == 0)
        {
            //cout << 3 + (n - (3 * k - 2 * x)) / k << "\n";
            vector<int> v;
            for (int i = 1; i <= x; ++i)
                v.push_back(i);
            int j = x + 1;
            for (int u = 0; u < k - x; ++u)
                v.push_back(j++);
            ans ^= rqry(v);
            v.clear();
            for (int i = 1; i <= x; ++i)
                v.push_back(i);
            for (int u = 0; u < k - x; ++u)
                v.push_back(j++);
            ans ^= rqry(v);
            v.clear();
            for (int i = 1; i <= x; ++i)
                v.push_back(i);
            for (int u = 0; u < k - x; ++u)
                v.push_back(j++);
            ans ^= rqry(v);
            for (int i = 0; i < (n - (3 * k - 2 * x)) / k; ++i)
            {
                v.clear();
                for (int u = 0; u < k; ++u)
                    v.push_back(j++);
                ans ^= rqry(v);
            }
            cout << "! " << ans << endl;
            k = n - k;
            for (int i = 1; i <= n; ++i)
            {
                if (!z[i])
                    return -1;
            }
            return 3 + (n - (3 * (n - k) - 2 * x)) / (n - k);
        }
    }
    k = n - k;

    vector<vector<int> > vv;
    for (int i = 1; i <= n; i += (n - k))
    {
        if (i + (n - k) - 1 <= n)
        {
            vector<int> v;
            for (int j = i; j < i + (n - k); ++j)
                v.push_back(j);
            vv.push_back(v);
        }
        else
        {
            for (int j = i; j <= n; ++j)
            {
                vector<int> v;
                for (int j = 1; j <= (n - k - 1); ++j)
                    v.push_back(j);
                v.push_back(j);
                vv.push_back(v);
            }
        }
    }

    for (int i = 0; i < sz(vv); ++i)
    {
        memset(cc, false, sizeof cc);
        for (int j = 0; j < sz(vv[i]); ++j)
            cc[vv[i][j]] = true;
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            if (!cc[i])
                v.push_back(i);
        }
        ans ^= qry(v);
    }
    cout << "! " << ans << endl;
    for (int i = 1; i <= n; ++i)
    {
        if (!z[i])
            return -1;
    }
    return sz(vv);
}

int d[1000006];
bool c[1000006];
int p[1000006];
int por()
{
    //cin >> n >> k;

    vector<int> v;
    for (int x = 0; x < (1 << n); ++x)
    {
        int q = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ++q;
        }
        if (q == k)
            v.push_back(x);
    }

    for (int x = 0; x < (1 << n); ++x)
        c[x] = false;

    queue<int> q;
    q.push(0);
    c[0] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == (1 << n) - 1)
        {
            cout << d[x] << "\n";
            int ans = d[x];
            while (x)
            {
                for (int i = 0; i < n; ++i)
                {
                    if ((p[x] & (1 << i)))
                        cout << '1';
                    else
                        cout << '0';
                }
                cout << "\n";
                x ^= p[x];
            }
            return ans;
        }
        for (int i = 0; i < sz(v); ++i)
        {
            int h = (x ^ v[i]);
            if (!c[h])
            {
                c[h] = true;
                d[h] = d[x] + 1;
                p[h] = v[i];
                q.push(h);
            }
        }
    }
    return -1;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (n = 1; n <= 10; ++n)
    {
        for (k = 1; k <= n; ++k)
        {
            if (por() != solv())
            {
                cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa " << n << ' ' << k << "\n";
            }
        }
    }
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        cin >> n >> k;
        solv();
    }
    return 0;
}