#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
char u[4][2];
long long ast(int x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        long long y = ast(x, n / 2);
        return y * y;
    }
    else
    {
        long long y = ast(x, n - 1);
        return x * y;
    }
}
int ci(char x)
{
    if ('0' <= x && x <= '9')
        return x - '0';
    else
        return 10 + x - 'A';
}
char ic(int x)
{
    if (0 <= x && x <= 9)
        return x + '0';
    else
        return (x - 10) + 'A';
}

int ha;
char bb[2];
int hb;
int n;
char a[N];

int b[N];

int main()
{
    cin >> ha >> bb;
    cin >> a;
    n = strlen(a);
    reverse(a, a + n);
    long long aa = 0;
    for (int i = 0; i < n; ++i)
        aa += ast(ha, i) * ci(a[i]);

    if (bb[0] == 'R')
    {
        vector<int> v;
        while (aa)
        {
            v.push_back(aa % 10);
            aa /= 10;
        }
        u[0][0] = 'I';
        u[0][1] = 'V';
        u[1][0] = 'X';
        u[1][1] = 'L';
        u[2][0] = 'C';
        u[2][1] = 'D';
        u[3][0] = 'M';
        vector<string> vv;
        for (int i = 0; i < v.size(); ++i)
        {
            string s;
            if (v[i] <= 3)
            {
                for (int j = 0; j < v[i]; ++j)
                    s += u[i][0];
            }
            else if (v[i] == 4)
            {
                s += u[i][0];
                s += u[i][1];
            }
            else if (v[i] <= 8)
            {
                s += u[i][1];
                for (int j = 0; j < v[i] - 5; ++j)
                    s += u[i][0];
            }
            else
            {
                s += u[i][0];
                s += u[i + 1][0];
            }
            vv.push_back(s);
        }
        reverse(vv.begin(), vv.end());
        for (int i = 0; i < vv.size(); ++i)
            cout << vv[i];
        cout << endl;
    }
    else
    {
        if (strlen(bb) == 1)
            hb = bb[0] - '0';
        else
            hb = (bb[0] - '0') * 10 + (bb[1] - '0');
        while (aa != 0)
        {
            for (int i = 0; i < N; ++i)
            {
                if (ast(hb, i) > aa)
                {
                    b[i - 1]++;
                    aa -= ast(hb, i - 1);
                    break;
                }
            }
        }
        bool z = false;
        for (int i = N - 1; i >= 0; --i)
        {
            if (z || b[i])
            {
                z = true;
                cout << ic(b[i]);
            }
        }
        if (!z)
            cout << 0;
        cout << endl;
    }
    return 0;
}