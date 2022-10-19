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
const int N = 100005;

vector<int> a;

void tp(vector<int> v)
{
    //return;
    if (v[0] == 0)
        reverse(all(v));
    for (int i = 0; i < sz(v); ++i)
        printf("%d", v[i]);
    printf("\n");
}

bool stg(vector<int> v)
{
    vector<int> u = v;
    reverse(all(u));
    vector<int> vv;
    int mn = 0;
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        vv.push_back((v[i] + u[i] + mn) % 10);
        mn = (v[i] + u[i] + mn) / 10;
    }
    if (mn)
        vv.push_back(mn);
    while (!vv.empty() && vv.back() == 0)
        vv.pop_back();
    reverse(all(vv));
    if (a == vv && (v[0] || v.back()))
    {
        tp(v);
        return true;
    }
    return false;
}

bool try1()
{
    vector<int> v1, v2;
    vector<int> vv;
    for (int i = 0, j = sz(a) - 1; ; ++i, --j)
    {
        if (i < j)
        {
            int mn = a[j];
            int s;
            if (!vv.empty() && vv.back() >= 10)
                --mn;
            mn = (mn + 10) % 10;
            if (mn == 9)
            {
                s = mn;
            }
            else
            {
                if (i > 0 && (v1.back() + v2.back()) % 10 != a[i - 1])
                    s = mn + 10;
                else
                    s = mn;
            }
            if (!vv.empty() && vv.back() >= 10)
                vv.push_back(s + 1);
            else
                vv.push_back(s);
            for (int x = 0; x < 10; ++x)
            {
                bool z = false;
                for (int y = 0; y < 10; ++y)
                {
                    if (x + y == s)
                    {
                        v1.push_back(x);
                        v2.push_back(y);
                        z = true;
                        break;
                    }
                }
                if (z)
                    break;
            }
        }
        else
        {
            for (int x = 0; x < 10; ++x)
            {
                vector<int> v;
                for (int i = 0; i < sz(v1); ++i)
                    v.push_back(v1[i]);
                v.push_back(x);
                for (int i = sz(v2) - 1; i >= 0; --i)
                    v.push_back(v2[i]);
                if (stg(v))
                    return true;
            }
            vector<int> v;
            for (int i = 0; i < sz(v1); ++i)
                v.push_back(v1[i]);
            for (int i = sz(v2) - 1; i >= 0; --i)
                v.push_back(v2[i]);
            if (stg(v))
                return true;
            return false;
        }
    }
}

bool try2()
{
    vector<int> v1, v2;
    vector<int> vv;
    for (int i = 1, j = sz(a) - 1; ; ++i, --j)
    {
        if (i < j)
        {
            int mn = a[j];
            int s;
            if (!vv.empty() && vv.back() >= 10)
                --mn;
            mn = (mn + 10) % 10;
            if (mn == 9)
            {
                s = mn;
            }
            else
            {
                if (i == 1 || (v1.back() + v2.back()) % 10 != a[i - 1])
                    s = mn + 10;
                else
                    s = mn;
            }
            if (!vv.empty() && vv.back() >= 10)
                vv.push_back(s + 1);
            else
                vv.push_back(s);
            for (int x = 0; x < 10; ++x)
            {
                bool z = false;
                for (int y = 0; y < 10; ++y)
                {
                    if (x + y == s)
                    {
                        v1.push_back(x);
                        v2.push_back(y);
                        z = true;
                        break;
                    }
                }
                if (z)
                    break;
            }
        }
        else
        {
            for (int x = 0; x < 10; ++x)
            {
                vector<int> v;
                for (int i = 0; i < sz(v1); ++i)
                    v.push_back(v1[i]);
                v.push_back(x);
                for (int i = sz(v2) - 1; i >= 0; --i)
                    v.push_back(v2[i]);
                if (stg(v))
                    return true;
            }
            vector<int> v;
            for (int i = 0; i < sz(v1); ++i)
                v.push_back(v1[i]);
            for (int i = sz(v2) - 1; i >= 0; --i)
                v.push_back(v2[i]);
            if (stg(v))
                return true;
            return false;
        }
    }
}

char s[N];
void ka()
{
    scanf(" %s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        a.push_back(s[i] - '0');
}

bool solv()
{
    if (try1())
        return true;
    if (try2())
        return true;
    printf("0\n");
    return false;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ka();
    solv();
    return 0;
    for (int x = 10000000; x < 10000000 + 200; ++x)
    {
        int y = 0;
        int xx = x;
        while (xx)
        {
            y = (y * 10) + (xx % 10);
            xx /= 10;
        }
        int s = x + y;
        a.clear();
        while (s)
        {
            a.push_back(s % 10);
            s /= 10;
        }
        reverse(all(a));
        if (!solv())
        {
            printf("%d\n%d\n", x, y);
            printf("WA\n");
            solv();
            return 0;
        }
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}