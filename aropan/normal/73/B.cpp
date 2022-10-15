#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define X first
#define S second

const int MAXN = 100001;

pair <int, string> a[MAXN];
int b[MAXN];
int n, m;
string s;

bool opr(const pair <int, string> &a, const pair <int, string> &b)
{
    return a.X > b.X || a.X >= b.X && a.S < b.S;
}

int main()
{
    #ifdef OFFLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].S >> a[i].X;
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(b, b + n);
    reverse(b, b + n);

    cin >> s;
    for (int i = 0; i < n; i++)
        if (a[i].S == s)
        {
            swap(a[0], a[i]);
            break;
        }
    sort(a + 1, a + n, opr);

    int left = 1, right = n;
    while (left < right)
    {
        int p = (left + right) >> 1;

        a[0].X += b[0];
        for (int i = 1; i < p; i++)
            a[i].X += b[i];
        for (int i = p; i < n; i++)
            a[i].X += b[n - (i - p + 1)];

        int k = 0;
        for (int i = 1; i < n; i++)
            k += opr(a[i], a[0]);

        if (k > p - 1)
            left = p + 1;
        else
            right = p;
        
        for (int i = 1; i < p; i++)
            a[i].X -= b[i];
        for (int i = p; i < n; i++)
            a[i].X -= b[n - (i - p + 1)];
        a[0].X -= b[0];
    }
    printf("%d ", left);

    reverse(b, b + n);
    reverse(a + 1, a + n);

    left = 1, right = n;
    while (left < right)
    {
        int p = (left + right) >> 1;

        a[0].X += b[0];
        for (int i = 1; i < p; i++)
            a[i].X += b[i];
        for (int i = p; i < n; i++)
            a[i].X += b[n - (i - p + 1)];

        int k = 0;
        for (int i = 1; i < n; i++)
            k += opr(a[0], a[i]);

        if (k > p - 1)
            left = p + 1;
        else
            right = p;
        
        for (int i = 1; i < p; i++)
            a[i].X -= b[i];
        for (int i = p; i < n; i++)
            a[i].X -= b[n - (i - p + 1)];
        a[0].X -= b[0];
    }

    printf("%d\n", n - left + 1);


    return 0;
}