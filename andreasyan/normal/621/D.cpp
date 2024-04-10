#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
string s[15] =
{
    "x^y^z",
    "x^z^y",
    "(x^y)^z",
    "(x^z)^y",
    "y^x^z",
    "y^z^x",
    "(y^x)^z",
    "(y^z)^x",
    "z^x^y",
    "z^y^x",
    "(z^x)^y",
    "(z^y)^x"
};

long double a[303];

long double x, y, z;
void conv(string s)
{
    if (s[0] == '(')
    {
        x = a[s[1]];
        y = a[s[3]];
        z = a[s[6]];
    }
    else
    {
        x = a[s[0]];
        y = a[s[2]];
        z = a[s[4]];
    }
}

long double f(string s)
{
    conv(s);
    if (s[0] == '(')
    {
        return y * z * log(x);
    }
    else
    {
        return pow(y, z) * log(x);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    cin >> a['x'] >> a['y'] >> a['z'];
    long double ans = f(s[0]);
    int ansi = 0;
    for (int i = 1; i < 12; ++i)
    {
        long double u = f(s[i]);
        if (u > ans)
        {
            ans = u;
            ansi = i;
        }
    }
    cout << s[ansi] << endl;
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}