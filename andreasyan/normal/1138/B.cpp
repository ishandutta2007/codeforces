#include <bits/stdc++.h>
using namespace std;
const int N = 5003;

int n;
char u0[N];
char u1[N];

vector<int> u[2][2];

int main()
{
    cin >> n >> u0 >> u1;
    for (int i = 0; i < n; ++i)
    {
        u[u0[i] - '0'][u1[i] - '0'].push_back(i + 1);
    }
    for (int i = 0; i <= u[1][0].size(); ++i)
    {
        for (int j = 0; j <= u[0][1].size(); ++j)
        {
            if (i < j)
            {
                if (u[1][1].size() < (j - i))
                    continue;
                if ((u[1][1].size() - (j - i)) % 2 == 1)
                    continue;
                int q0 = i + (u[0][1].size() - j) + (j - i) + (u[1][1].size() - (j - i)) / 2;
                int q1 = j + (u[1][0].size() - i) + (u[1][1].size() - (j - i)) / 2;
                if (q0 <= n / 2 && q1 <= n / 2)
                {
                    for (int k = 0; k < i; ++k)
                        cout << u[1][0][k] << ' ';
                    for (int k = 0; k < (u[0][1].size() - j); ++k)
                        cout << u[0][1][k] << ' ';
                    for (int k = 0; k < (j - i); ++k)
                        cout << u[1][1][k] << ' ';
                    for (int k = (j - i); k < u[1][1].size(); ++k)
                    {
                        if (k % 2 == 0)
                            cout << u[1][1][k] << ' ';
                    }
                    for (int k = 0; k < (n / 2 - q0); ++k)
                        cout << u[0][0][k] << ' ';
                    cout << endl;
                    return 0;
                }
            }
            else
            {
                if (u[1][1].size() < (i - j))
                    continue;
                if ((u[1][1].size() - (i - j)) % 2 == 1)
                    continue;
                int q0 = i + (u[0][1].size() - j) + (u[1][1].size() - (i - j)) / 2;
                int q1 = j + (u[1][0].size() - i) + (i - j) + (u[1][1].size() - (i - j)) / 2;
                if (q0 <= n / 2 && q1 <= n / 2)
                {
                    for (int k = 0; k < i; ++k)
                        cout << u[1][0][k] << ' ';
                    for (int k = 0; k < (u[0][1].size() - j); ++k)
                        cout << u[0][1][k] << ' ';
                    for (int k = (i - j); k < u[1][1].size(); ++k)
                    {
                        if (k % 2 == 0)
                            cout << u[1][1][k] << ' ';
                    }
                    for (int k = 0; k < (n / 2 - q0); ++k)
                        cout << u[0][0][k] << ' ';
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}