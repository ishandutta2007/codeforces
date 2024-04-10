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
const int N = 122, M = 1000000007;

int n;
int a[N][6];
int qq[6];

vector<pair<int, pair<int, int> > > v;
void bs1(int j, int x)
{
    int l = 1, r = M;
    int u = -1;
    while (l <= r)
    {
        int q = (l + r) / 2;
        if ((qq[j] + q) * 1LL * x > (n + q))
        {
            u = q;
            r = q - 1;
        }
        else
            l = q + 1;
    }
    if (u != -1)
        v.push_back(m_p(u, m_p(j, -500)));
}
void bs2(int j, int x)
{
    int l = 1, r = M;
    int u = -1;
    while (l <= r)
    {
        int q = (l + r) / 2;
        if (qq[j] * 1LL * x <= (n + q))
        {
            u = q;
            r = q - 1;
        }
        else
            l = q + 1;
    }
    if (u != -1)
        v.push_back(m_p(u, m_p(j, 500)));
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 5; ++j)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            if (a[i][j] != -1)
                qq[j]++;
        }
    }

    int score[6] = {};
    for (int j = 1; j <= 5; ++j)
    {
        if (qq[j] * 2LL > n)
            score[j] = 500;
        else if (qq[j] * 4LL > n)
            score[j] = 1000;
        else if (qq[j] * 8LL > n)
            score[j] = 1500;
        else if (qq[j] * 16LL > n)
            score[j] = 2000;
        else if (qq[j] * 32LL > n)
            score[j] = 2500;
        else
            score[j] = 3000;
        if (a[1][j] != -1 && a[2][j] != -1 && a[1][j] > a[2][j])
        {
            if (score[j] >= 3000)
                bs1(j, 32);
            if (score[j] >= 2500)
                bs1(j, 16);
            if (score[j] >= 2000)
                bs1(j, 8);
            if (score[j] >= 1500)
                bs1(j, 4);
            if (score[j] >= 1000)
                bs1(j, 2);
        }
        else
        {
            if (score[j] <= 500)
                bs2(j, 2);
            if (score[j] <= 1000)
                bs2(j, 4);
            if (score[j] <= 1500)
                bs2(j, 8);
            if (score[j] <= 2000)
                bs2(j, 16);
            if (score[j] <= 2500)
                bs2(j, 32);
        }
    }

    v.push_back(m_p(0, m_p(0, 0)));
    sort(all(v));
    for (int i = 0; i < sz(v); ++i)
    {
        score[v[i].se.fi] += v[i].se.se;
        if (i == sz(v) - 1 || (v[i + 1].fi != v[i].fi))
        {
            int s[3] = {};
            for (int i = 1; i <= 2; ++i)
            {
                for (int j = 1; j <= 5; ++j)
                {
                    if (a[i][j] != -1)
                        s[i] += (score[j] - score[j] / 250 * a[i][j]);
                }
            }
            if (s[1] > s[2])
            {
                cout << v[i].fi << "\n";
                return;
            }
        }
    }
    cout << "-1\n";

    /*int s[3] = {};
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            int score;
            if (qq[j] * 2LL > nn)
                score = 500;
            else if (qq[j] * 4LL > nn)
                score = 1000;
            else if (qq[j] * 8LL > nn)
                score = 1500;
            else if (qq[j] * 16LL > nn)
                score = 2000;
            else if (qq[j] * 32LL > nn)
                score = 2500;
            else
                score = 3000;
            if (a[i][j] != -1)
                s[i] += (score - score / 250 * a[i][j]);
        }
    }*/
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
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