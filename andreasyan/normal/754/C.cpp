#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;

int n, m;
string name[N];
map<string, int> mp;
pair<string, string> mess[N];

int p[N][N];

void solv()
{
    mp.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> name[i];
        mp[name[i]] = i;
    }
    cin >> m;
    getline(cin, mess[0].first);
    for (int i = 1; i <= m; ++i)
    {
        mess[i].first = "";
        mess[i].second = "";
        string s;
        getline(cin, s);
        bool z = false;
        int sn = s.size();
        for (int j = 0; j < sn; ++j)
        {
            if (z)
            {
                mess[i].second += s[j];
            }
            else
            {
                if (s[j] == ':')
                    z = true;
                else
                    mess[i].first += s[j];
            }
        }
    }
    memset(p, false, sizeof p);
    for (int i = 1; i <= m; ++i)
    {
        if (mess[i].first == "?")
        {
            int sn = mess[i].second.size();
            set<int> s;
            for (int l = 0; l < sn; ++l)
            {
                if (l && ('0' <= mess[i].second[l - 1] && mess[i].second[l - 1] <= '9'))
                    continue;
                if (l && ('a' <= mess[i].second[l - 1] && mess[i].second[l - 1] <= 'z'))
                    continue;
                if (l && ('A' <= mess[i].second[l - 1] && mess[i].second[l - 1] <= 'Z'))
                    continue;
                string u = "";
                for (int r = l; r < sn; ++r)
                {
                    if (r - l + 1 > 10)
                        break;
                    u += mess[i].second[r];
                    if (r < sn - 1 && ('0' <= mess[i].second[r + 1] && mess[i].second[r + 1] <= '9'))
                        continue;
                    if (r < sn - 1 && ('a' <= mess[i].second[r + 1] && mess[i].second[r + 1] <= 'z'))
                        continue;
                    if (r < sn - 1 && ('A' <= mess[i].second[r + 1] && mess[i].second[r + 1] <= 'Z'))
                        continue;
                    if (mp.find(u) != mp.end())
                        s.insert(mp[u]);
                }
            }
            for (int j = 1; j <= n; ++j)
            {
                if (s.find(j) != s.end())
                    continue;
                if (i == 1)
                {
                    p[i][j] = -1;
                    continue;
                }
                for (int k = 1; k <= n; ++k)
                {
                    if (k == j)
                        continue;
                    if (p[i - 1][k])
                        p[i][j] = k;
                }
            }
        }
        else
        {
            if (i == 1)
            {
                p[i][mp[mess[i].first]] = -1;
                continue;
            }
            for (int j = 1; j <= n; ++j)
            {
                if (j == mp[mess[i].first])
                    continue;
                if (p[i - 1][j])
                    p[i][mp[mess[i].first]] = j;
            }
        }
    }
    for (int j = 1; j <= n; ++j)
    {
        if (p[m][j])
        {
            int i = m;
            while (i)
            {
                mess[i].first = name[j];
                j = p[i][j];
                --i;
            }
            for (int i = 1; i <= m; ++i)
            {
                cout << mess[i].first << ":" << mess[i].second << endl;
            }
            return;
        }
    }
    cout << "Impossible" << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}