#include <bits/stdc++.h>
using namespace std;
struct ban
{
    vector<short> v;
    ban(){}
    ban(int x)
    {
        while (x)
        {
            v.push_back(x % 10);
            x /= 10;
        }
        reverse(v.begin(), v.end());
    }
    ban(vector<short> v)
    {
        this->v = v;
    }
};
ban operator+(const ban& a, const ban& b)
{
    vector<short> aa = a.v;
    vector<short> bb = b.v;
    reverse(aa.begin(), aa.end());
    reverse(bb.begin(), bb.end());
    while (aa.size() > bb.size())
        bb.push_back(0);
    while (bb.size() > aa.size())
        aa.push_back(0);
    int mn = 0;
    vector<short> res;
    for (int i = 0; i < aa.size(); ++i)
    {
        res.push_back((aa[i] + bb[i] + mn) % 10);
        mn = (aa[i] + bb[i] + mn) / 10;
    }
    res.push_back(mn);
    while (!res.empty() && res.back() == 0)
        res.pop_back();
    reverse(res.begin(), res.end());
    return ban(res);
}
ban operator*(const ban& a, const ban& b)
{
    ban res;
    for (int i = 0; i < a.v.size(); ++i)
    {
        ban c;
        for (int j = 0; j < a.v[i]; ++j)
            c = c + b;
        for (int j = 0; j < a.v.size() - i - 1; ++j)
        {
            c.v.push_back(0);
        }
        res = res + c;
    }
    return res;
}
bool operator<(const ban& a, const ban& b)
{
    if (a.v.size() < b.v.size())
        return true;
    if (a.v.size() > b.v.size())
        return false;
    for (int i = 0; i < a.v.size(); ++i)
    {
        if (a.v[i] < b.v[i])
            return true;
        if (a.v[i] > b.v[i])
            return false;
    }
    return false;
}
void dz(ban& a)
{
    reverse(a.v.begin(), a.v.end());
    while (!a.v.empty() && a.v.back() == 0)
        a.v.pop_back();
    reverse(a.v.begin(), a.v.end());
}

void tp(ban t)
{
    dz(t);
    if (t.v.empty())
        cout << 0;
    for (int i = 0; i < t.v.size(); ++i)
        cout << t.v[i];
    cout << endl;
}
ban INF;

int n;
int m;
char a[66];

const int p = 66;

ban ast[p];

ban dp[66][p];

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 20; ++i)
        INF.v.push_back(9);
    cin >> n;
    cin >> a;
    m = strlen(a);

    ast[0] = ban(1);
    for (int i = 1; i < p; ++i)
        ast[i] = ast[i - 1] * ban(n);

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j < p; ++j)
        {
            dp[i][j] = INF;
        }
    }

    dp[m][0].v.clear();
    for (int i = m; i > 0; --i)
    {
        for (int f = 0; f < p; ++f)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (a[j] == '0' && (j != i - 1))
                    continue;
                ban t;
                for (int k = j; k < i; ++k)
                    t.v.push_back(a[k] - '0');

                dz(t);
                if (!(t < ban(n)))
                    break;
                ban u = dp[i][f] + (t * ast[f]);
                dz(u);
                if (u < dp[j][f + 1])
                    dp[j][f + 1] = u;
            }
        }
    }
    ban ans = INF;
    for (int f = 0; f < p; ++f)
    {
        if (dp[0][f] < ans)
            ans = dp[0][f];
    }
    tp(ans);
    return 0;
}