#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1111;
const int MAXD = 6;
const int INF = 2012;

int a[MAXN];
int d[MAXD];
int n;

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    cin >> n;

    d[0] = 1;
    for (int i = 1; i < MAXD; i++)
        d[i] = d[i - 1] * 10;

    a[0] = 1000;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        a[i] = INF;
        for (int j = 0; j < 4; j++)
            for (int number = 0; number < 10; number++)
            {
                int y = x - (x % d[j + 1]) / d[j] * d[j] + number * d[j];

                if (a[i - 1] <= y)
                    a[i] = min(a[i], y);
            }
    }

    if (a[n] == INF)
    {
        cout << "No solution" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << endl;
    }
    return 0;
}