#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;

const int INF = (int)(1e9 + 1337);
const int64 LINF = (int64)(4e18);
const double EPS = (double)(1e-11);
#define sq(x) ((x)*(x))
#define FAIL() ((*(int*)(0))++)

struct oper
{
    int f[2];
    oper() {}
    oper(int v)
    {
        f[0] = f[1] = v;
    }
    oper(int v0, int v1)
    {
        f[0] = v0;
        f[1] = v1;
    }
};

oper operator&(const oper &a, const oper &b)
{
    return oper(a.f[0] & b.f[0], a.f[1] & b.f[1]);
}

oper operator|(const oper &a, const oper &b)
{
    return oper(a.f[0] | b.f[0], a.f[1] | b.f[1]);
}

oper operator^(const oper &a, const oper &b)
{
    return oper(a.f[0] ^ b.f[0], a.f[1] ^ b.f[1]);
}

int n, m;

struct expr
{
    int d[1000][2];
};

expr operator&(const expr &a, const expr &b)
{
    expr res;
    for(int i = 0; i < m; i++)
        for(int j = 0; j <= 1; j++)
            res.d[i][j] = a.d[i][j] & b.d[i][j];
    return res;
}

expr operator|(const expr &a, const expr &b)
{
    expr res;
    for(int i = 0; i < m; i++)
        for(int j = 0; j <= 1; j++)
            res.d[i][j] = a.d[i][j] | b.d[i][j];
    return res;
}

expr operator^(const expr &a, const expr &b)
{
    expr res;
    for(int i = 0; i < m; i++)
        for(int j = 0; j <= 1; j++)
            res.d[i][j] = a.d[i][j] ^ b.d[i][j];
    return res;
}

expr a[5010];
map<string, int> id;
int ctr[1010][2];

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        for(int j = 0; j <= 1; j++)
            a[0].d[i][j] = j;
    id["?"] = 0;
    for(int i = 1; i <= n; i++)
    {
        string v, op, v1, v2;
        cin >> v >> op >> v1;
        id[v] = i;
        if('0' == v1[0] || v1[0] == '1')
        {
            for(int j = 0; j < m; j++)
                a[i].d[j][0] = a[i].d[j][1] = v1[j] - '0';
        }
        else
        {
            cin >> op >> v2;
            expr& o1 = a[id[v1]];
            expr& o2 = a[id[v2]];
            if(op == "AND")
                a[i] = o1 & o2;
            else if(op == "OR")
                a[i] = o1 | o2;
            else
                a[i] = o1 ^ o2;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k <= 1; k++)
                ctr[j][k] += a[i].d[j][k];
    string a, b;
    for(int i = 0; i < m; i++)
    {
        if(ctr[i][1] < ctr[i][0])
            a += '1';
        else
            a += '0';
        if(ctr[i][1] > ctr[i][0])
            b += '1';
        else
            b += '0';
    }
    cout << a << '\n' << b << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}