#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void fail()
{
    cout << "Impossible\n";
    exit(0);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[2][2];
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
    int z = -1, o = -1;
    const int maxn = 1e6;
    for(int i = 0; i <= maxn; i++)
    {
        if(i * (i - 1) / 2 == a[0][0])
            z = i;
        if(i * (i - 1) / 2 == a[1][1])
            o = i;
    }

    if(z == -1 || o == -1)
        fail();
    int O = o, Z = z;
    int AA[2][2];
    AA[0][0] = a[0][0];
    AA[0][1] = a[0][1];
    AA[1][0] = a[1][0];
    AA[1][1] = a[1][1];
    for(int A = 0; A <= (a[0][0] == 0); A++)
    for(int B = 0; B <= (a[1][1] == 0); B++)
    {
        int a[2][2] = {{AA[0][0], AA[0][1]}, {AA[1][0], AA[1][1]}};
        int z = Z - A;
        int o = O - B;
        //cout << z << ' ' << o << endl;
        int n = o + z;
        if(n > maxn || n == 0)
            continue;
        string s;
        for(int i = 0; i < n; i++)
        {
            if(o <= a[0][1] && z > 0)
            {
                a[0][1] -= o;
                z--;
                s += "0";
            }
            else
            {
                a[1][0] -= z;
                o--;
                s += "1";
            }
        }
        if(a[0][1] == 0 && a[1][0] == 0 && o == 0 && z == 0)
        {
            cout << s << "\n";
            return 0;
        }
    }
    fail();
    return 0;
}