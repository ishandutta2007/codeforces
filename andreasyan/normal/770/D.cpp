#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];
int x[N];

char ans[N * 4][N * 20];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> a;
    stack<int> s;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '[')
            s.push(i);
        else
        {
            x[i] = s.size() - 1;
            x[s.top()] = s.size() - 1;
            s.pop();
        }
    }

    int maxu = 0;
    for (int i = 0; i < n; ++i)
        maxu = max(maxu, x[i]);

    for (int i = 0; i < N * 4; ++i)
    {
        for (int j = 0; j < N * 20; ++j)
            ans[i][j] = ' ';
    }

    int z = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '[')
        {
            int l = x[i];
            int r = maxu * 2 + 1 + 2 - x[i] - 1;
            for (int j = l + 1; j < r; ++j)
                ans[z][j] = '|';
            ans[z][l] = '+';
            ans[z][r] = '+';
            ans[z + 1][l] = '-';
            ans[z + 1][r] = '-';
            z++;
            if (a[i + 1] == ']')
                z += 3;
        }
        else
        {
            int l = x[i];
            int r = maxu * 2 + 1 + 1 - x[i];
            for (int j = l + 1; j < r; ++j)
                ans[z][j] = '|';
            ans[z][l] = '+';
            ans[z][r] = '+';
            ans[z - 1][l] = '-';
            ans[z - 1][r] = '-';
            z++;
        }
    }

    for (int j = 0; j < maxu * 2 + 1 + 2; ++j)
    {
        for (int i = 0; i < z; ++i)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}