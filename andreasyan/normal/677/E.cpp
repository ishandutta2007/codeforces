#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003;
const long long M = 1000000007;

long long ast(long long x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        long long y = ast(x, n / 2);
        return (y * y) % M;
    }
    else
    {
        long long y = ast(x, n - 1);
        return (y * x) % M;
    }
}

long long baz(long long x, long long y)
{
    return (x * ast(y, M - 2)) % M;
}

void ass(vector<pair<int, int> >& v, int n)
{
    for (int i = 0; i < n; ++i)
        v.push_back(m_p(0, 0));
}


pair<int, int> operator*(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p(a.first + b.first, a.second + b.second);
}

pair<int, int> operator/(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p(a.first - b.first, a.second - b.second);
}

bool operator!(const pair<int, int>& a)
{
    return (a.first < 0 && a.second < 0);
}

bool operator>(const pair<int, int>& x, const pair<int, int>& y)
{
    if (x.first < 0 || x.second < 0)
        cout << "";
    pair<int, int> a = x, b = y;
    if (a.second == b.second)
        return a.first > b.first;
    double t = (b.first - a.first) * 1.0 / (a.second - b.second) * 1.0;
    if (a.second < b.second)
    {
        if (t >= 2)
            return true;
        return pow(2, t) > 3.0;
    }
    else
    {
        if (t >= 2)
            return false;
        return pow(2, t) < 3.0;
    }
}

void ubd(vector<pair<int, int> >& t, int tl, int tr, int x, int y, int pos)
{
    tl++;
    tr++;
    x++;
    pair<int, int> z;
    if (y == 0)
        z = m_p(-N, -N);
    else if (y == 1)
        z = m_p(0, 0);
    else if (y == 2)
        z = m_p(1, 0);
    else
        z = m_p(0, 1);
    while (x <= tr)
    {
        t[x] = t[x] * z;
        x += (x & (-x));
    }
}

pair<int, int> qry(vector<pair<int, int> >& t, int tl, int tr, int l, int r, int pos)
{
    if (l < tl || r > tr)
        return m_p(-N, -N);
    tl++;
    tr++;
    l++;
    r++;
    pair<int, int> ans = m_p(0, 0);
    int x = r;
    while (x > 0)
    {
        ans = ans * t[x];
        x -= (x & (-x));
    }
    x = l - 1;
    while (x > 0)
    {
        ans = ans / t[x];
        x -= (x & (-x));
    }
    return ans;
}

int n;
char b[N][N];
int a[N][N];

vector<pair<int, int> > t1[N], t2[N];
vector<pair<int, int > > b1[N * 2], b2[N * 2];
int pos1[N][N], pos2[N][N];
vector<pair<int, int> > t3[N * 2], t4[N * 2];

pair<int, int> ans;
int main()
{
    bool zz = true;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            a[i][j] = b[i][j] - '0';
            if (a[i][j])
                 zz = false;
        }
    }
    if (zz)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        ass(t1[i], n * 4);
        for (int j = 0; j < n; ++j)
        {
            ubd(t1[i], 0, n - 1, j, a[i][j], 1);
        }
    }
    for (int j = 0; j < n; ++j)
    {
        ass(t2[j], n * 4);
        for (int i = 0; i < n; ++i)
        {
            ubd(t2[j], 0, n - 1, i, a[i][j], 1);
        }
    }
    for (int t = -(n - 1); t <= (n - 1); ++t)
    {
        for (int i = 0; i < n; ++i)
        {
            int j = t + i;
            t += (n - 1);
            if (0 <= j && j < n)
                b1[t].push_back(m_p(i, j));
            t -= (n - 1);
        }
        t += (n - 1);
        ass(t3[t], b1[t].size() * 4);
        for (int i = 0; i < b1[t].size(); ++i)
        {
            ubd(t3[t], 0, b1[t].size() - 1, i, a[b1[t][i].first][b1[t][i].second], 1);
            pos1[b1[t][i].first][b1[t][i].second] = i;
        }
        t -= (n - 1);
    }
    for (int g = 0; g <= (n - 1) + (n - 1); ++g)
    {
        for (int i = 0; i < n; ++i)
        {
            int j = g - i;
            if (0 <= j && j < n)
                b2[g].push_back(m_p(i, j));
        }
        ass(t4[g], b2[g].size() * 4);
        for (int i = 0; i < b2[g].size(); ++i)
        {
            ubd(t4[g], 0, b2[g].size() - 1, i, a[b2[g][i].first][b2[g][i].second], 1);
            pos2[b2[g][i].first][b2[g][i].second] = i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!a[i][j])
                continue;
            int l = 0, r = n / 2;
            while ((r - l) > 4)
            {
                int m = (l + r) / 2;
                int dd = i - m;
                int uu = i + m;
                int ll = j - m;
                int rr = j + m;
                pair<int, int> z = (qry(t1[i], 0, n - 1, ll, rr, 1) * qry(t2[j], 0, n - 1, dd, uu, 1));
                if (a[i][j] == 2)
                    z.first--;
                if (a[i][j] == 3)
                    z.second--;
                if (!!(z))
                    l = m;
                else
                    r = m;
            }
            for (int m = r; m >= l; --m)
            {
                int dd = i - m;
                int uu = i + m;
                int ll = j - m;
                int rr = j + m;
                pair<int, int> z = (qry(t1[i], 0, n - 1, ll, rr, 1) * qry(t2[j], 0, n - 1, dd, uu, 1));
                if (a[i][j] == 2)
                    z.first--;
                if (a[i][j] == 3)
                    z.second--;
                if (!!(z))
                {
                    if ((z) > ans)
                        ans = z;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!a[i][j])
                continue;
            int l = 0, r = n / 2;
            int t = j - i;
            int g = i + j;
            t += (n - 1);
            while ((r - l) > 4)
            {
                int m = (l + r) / 2;
                int dd = pos1[i][j] - m;
                int uu = pos1[i][j] + m;
                int ll = pos2[i][j] - m;
                int rr = pos2[i][j] + m;
                pair<int, int> z = (qry(t3[t], 0, b1[t].size() - 1, dd, uu, 1) * qry(t4[g], 0, b2[g].size() - 1, ll, rr, 1));
                if (a[i][j] == 2)
                    z.first--;
                if (a[i][j] == 3)
                    z.second--;
                if (!!(z))
                    l = m;
                else
                    r = m;
            }
            for (int m = r; m >= l; --m)
            {
                int dd = pos1[i][j] - m;
                int uu = pos1[i][j] + m;
                int ll = pos2[i][j] - m;
                int rr = pos2[i][j] + m;
                pair<int, int> z = (qry(t3[t], 0, b1[t].size() - 1, dd, uu, 1) * qry(t4[g], 0, b2[g].size() - 1, ll, rr, 1));
                if (a[i][j] == 2)
                    z.first--;
                if (a[i][j] == 3)
                    z.second--;
                if (!!(z))
                {
                    if ((z) > ans)
                        ans = z;
                    break;
                }
            }
        }
    }
    cout << (ast(2, ans.first) * ast(3, ans.second)) % M << endl;
    return 0;
}