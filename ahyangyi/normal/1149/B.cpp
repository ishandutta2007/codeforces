#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[251][251][251];

int main()
{
    std::ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    string u;
    cin >> u;

    vector<vector<int>> next(n + 2, vector<int>(26));

    {
        vector<int> temp(26, n + 1);
        next[n + 1] = temp;
        next[n] = temp;
        for (int i = n - 1; i >= 0; --i)
        {
            temp[u[i]-'a'] = i + 1;
            next[i] = temp;
        }
    }

    vector<int> a[3];
    dp[0][0][0] = 0;

    for (int i = 0; i < q; ++i)
    {
        char sign;
        cin >> sign;

        if (sign == '+')
        {
            int pos;
            char c;

            cin >> pos >> c;
            a[pos - 1].push_back(c - 'a');

            if (pos == 1)
            {
                int A = a[0].size();
                int B = a[1].size();
                int C = a[2].size();
                for (int b = 0; b <= B; ++b)
                    for (int c = 0; c <= C; ++c)
                    {
                        dp[A][b][c] = n + 1;
                        {
                            dp[A][b][c] = std::min(dp[A][b][c], next[dp[A - 1][b][c]][a[0][A - 1]]);
                        }
                        if (b > 0)
                        {
                            dp[A][b][c] = std::min(dp[A][b][c], next[dp[A][b - 1][c]][a[1][b - 1]]);
                        }
                        if (c > 0)
                        {
                            dp[A][b][c] = std::min(dp[A][b][c], next[dp[A][b][c - 1]][a[2][c - 1]]);
                        }
                    }
            }
            else if (pos == 2)
            {
                int A = a[1].size();
                int B = a[2].size();
                int C = a[0].size();
                for (int b = 0; b <= B; ++b)
                    for (int c = 0; c <= C; ++c)
                    {
                        dp[c][A][b] = n + 1;
                        {
                            dp[c][A][b] = std::min(dp[c][A][b], next[dp[c][A - 1][b]][a[1][A - 1]]);
                        }
                        if (b > 0)
                        {
                            dp[c][A][b] = std::min(dp[c][A][b], next[dp[c][A][b - 1]][a[2][b - 1]]);
                        }
                        if (c > 0)
                        {
                            dp[c][A][b] = std::min(dp[c][A][b], next[dp[c - 1][A][b]][a[0][c - 1]]);
                        }
                    }
            }
            else
            {
                int A = a[2].size();
                int B = a[0].size();
                int C = a[1].size();
                for (int b = 0; b <= B; ++b)
                    for (int c = 0; c <= C; ++c)
                    {
                        dp[b][c][A] = n + 1;
                        {
                            dp[b][c][A] = std::min(dp[b][c][A], next[dp[b][c][A - 1]][a[2][A - 1]]);
                        }
                        if (b > 0)
                        {
                            dp[b][c][A] = std::min(dp[b][c][A], next[dp[b - 1][c][A]][a[0][b - 1]]);
                        }
                        if (c > 0)
                        {
                            dp[b][c][A] = std::min(dp[b][c][A], next[dp[b][c - 1][A]][a[1][c - 1]]);
                        }
                    }
            }
        }
        else
        {
            int pos;
            cin >> pos;
            a[pos - 1].pop_back();
        }
        if (dp[a[0].size()][a[1].size()][a[2].size()] < n + 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}