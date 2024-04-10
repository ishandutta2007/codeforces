#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double

const int MAXN = 100;
int a[MAXN][MAXN];
int n;

bool ask(int x1, int y1, int x2, int y2)
{
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    int u;
    cin >> u;
    return u ^ 1;
}

void magic()
{
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < n; e++)
        {
            if ((i + e) % 2)
                a[i][e] ^= 1;
        }
    }
}

void print()
{
    cout << "!\n";
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < n; e++)
            cout << a[i][e];
        cout << "\n";
    }
    cout.flush();
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a[0][0] = 1;
    a[n - 1][n - 1] = 0;
    for (int i = 2; i < n; i += 2)
    {
        a[i][0] = (a[i - 2][0] ^ ask(i - 2, 0, i, 0));
        a[0][i] = (a[0][i - 2] ^ ask(0, i - 2, 0, i));
    }
    for (int sum = 2; sum < 2 * (n - 1); sum += 2)
    {
        for (int e = 1; e < sum && e < n; e++)
        {
            int i = sum - e;
            if (i <= 0 || i >= n)
                continue;
            a[i][e] = (a[i - 1][e - 1] ^ ask(i - 1, e - 1, i, e));
        }
    }
    a[0][1] = ask(0, 1, 1, 2);
    a[1][0] = ask(1, 0, 1, 2);
    for (int i = 3; i < n; i += 2)
    {
        a[i][0] = (a[i - 2][0] ^ ask(i - 2, 0, i, 0));
        a[0][i] = (a[0][i - 2] ^ ask(0, i - 2, 0, i));
    }
    for (int sum = 3; sum <= 2 * (n - 1); sum += 2)
    {
        for (int e = 1; e < sum && e < n; e++)
        {
            int i = sum - e;
            if (i == 1 && e == 2)
                continue;
            if (i <= 0 || i >= n)
                continue;
            a[i][e] = (a[i - 1][e - 1] ^ ask(i - 1, e - 1, i, e));
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int e = 1; e < n; e++)
        {
            if (a[i][e] != a[i + 1][e - 1])
            {
                if (e - 2 >= 0)
                {
                    if ((ask(i, e - 2, i + 1, e) ^ a[i][e - 2]) != a[i + 1][e])
                        magic();

                }
                else if (i - 1 >= 0)
                {
                    if ((ask(i - 1, e - 1, i + 1, e) ^ a[i - 1][e - 1]) != a[i + 1][e])
                        magic();
                }
                else
                {
                    if ((ask(i, e - 1, i + 1, e + 1) ^ a[i + 1][e + 1]) != a[i][e - 1])
                        magic();
                }
                print();
                return 0;
            }
        }
    }
    for (int sum = 0; sum <= 2 * (n - 1) - 3; sum++)
    {
        int x1 = min(n - 1, sum);
        int x2 = min(n - 1, sum + 1);
        int x3 = min(n - 1, sum + 2);
        int x4 = min(n - 1, sum + 3);
        if ((a[x1][sum - x1] ^ a[x3][sum + 2 - x3]) == (a[x2][sum + 1 - x2] ^ a[x4][sum + 3 - x4]))
        {
            if (ask(x1, sum - x1, x4, sum + 3 - x4) != (a[x1][sum - x1] ^ a[x4][sum + 3 - x4]))
                magic();
            print();
            return 0;
        }
    }
    print();
}