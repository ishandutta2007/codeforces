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
const int N = 102;

int n;

map<vector<int>, int> mp;

int rec(vector<int> v)
{
    if (v.empty())
        return 0;
    sort(all(v));
    vector<int> vv;
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
            vv.push_back(v[i]);
    }
    v = vv;
    if (mp.find(v) != mp.end())
        return mp[v];
    set<int> s;
    for (int q = 1; q <= v.back(); ++q)
    {
        vector<int> nv;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] < q)
                nv.push_back(v[i]);
            else if (v[i] > q)
                nv.push_back(v[i] - q);
        }
        s.insert(rec(nv));
    }
    for (int i = 0; ; ++i)
    {
        if (s.find(i) == s.end())
            return mp[v] = i;
    }
}

void solv()
{
    scanf("%d", &n);
    map<int, vector<int> > mp;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        for (int i = 2; i * i <= x; ++i)
        {
            if (x % i == 0)
            {
                int q = 0;
                while (x % i == 0)
                {
                    x /= i;
                    ++q;
                }
                mp[i].push_back(q);
            }
        }
        if (x > 1)
            mp[x].push_back(1);
    }
    int ans = 0;

    for (auto it = mp.begin(); it != mp.end(); ++it)
        ans ^= rec(it->se);

    if (ans)
        printf("Mojtaba\n");
    else
        printf("Arpa\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}