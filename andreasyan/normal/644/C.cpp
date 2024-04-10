#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2000006;
pair<int, int> M = m_p(153648241, 505343141);
const int P = 307;
typedef pair<pair<int, int>, long long> hsh;

bool isprime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

hsh sum(const hsh& a, const hsh& b)
{
    return m_p(m_p((a.first.first + b.first.first) % M.first, (a.first.second + b.first.second) % M.second), a.second + b.second);
}

hsh pro(const hsh& a, int x)
{
    return m_p(m_p((a.first.first * 1LL * x) % M.first, (a.first.second * 1LL * x) % M.second), a.second * x);
}

hsh ast[N];

void pre()
{
    ast[0] = m_p(m_p(1, 1), 1);
    for (int i = 1; i < N; ++i)
        ast[i] = pro(ast[i - 1], P);
}

map<string, vector<string> > v;
map<hsh, vector<string> > ans;

void solv()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int m = s.size();
        string a = "http://", b;
        bool z = false;
        for (int i = 7; i < m; ++i)
        {
            if (s[i] == '/')
            {
                z = true;
                for (; i < m; ++i)
                    b += s[i];
                break;
            }
            a += s[i];
        }
        if (!z)
        {
            b = "@";
        }
        //cout << a << ' ' << b << endl;
        v[a].push_back(b);
    }
    for (map<string, vector<string> >::iterator it = v.begin(); it != v.end(); ++it)
    {
        sort(it->second.begin(), it->second.end());
        hsh u = m_p(m_p(0, 0), 0);
        int z = 0;
        for (int j = 0; j < it->second.size(); ++j)
        {
            if (j && it->second[j] == it->second[j - 1])
                continue;
            int m = it->second[j].size();
            for (int k = 0; k < m; ++k)
            {
                u = sum(u, pro(ast[z++], it->second[j][k]));
            }
            u = sum(u, pro(ast[z++], '_'));
        }
        ans[u].push_back(it->first);
    }
    int ansq = 0;
    for (map<hsh, vector<string> >::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        if (it->second.size() > 1)
            ++ansq;
    }
    cout << ansq << endl;
    for (map<hsh, vector<string> >::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        if (it->second.size() > 1)
        {
            for (int i = 0; i < it->second.size(); ++i)
                cout << it->second[i] << ' ';
            cout << endl;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}