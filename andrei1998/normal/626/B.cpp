#include <iostream>
#include <string>

using namespace std;

int dp[205][205][205];

int dfs(int b, int g, int r) {
    if (dp[b][g][r])
        return dp[b][g][r];

    if (b + g + r == 1) {
        if (b)
            dp[b][g][r] = 4;
        else if (g)
            dp[b][g][r] = 2;
        else if (r)
            dp[b][g][r] = 1;
    }
    else {
        if (b >= 2)
            dp[b][g][r] |= dfs(b - 1, g, r);
        if (g >= 2)
            dp[b][g][r] |= dfs(b, g - 1, r);
        if (r >= 2)
            dp[b][g][r] |= dfs(b, g, r - 1);

        if (b >= 1 && g >= 1)
            dp[b][g][r] |= dfs(b - 1, g - 1, r + 1);
        if (b >= 1 && r >= 1)
            dp[b][g][r] |= dfs(b - 1, g + 1, r - 1);
        if (g >= 1 && r >= 1)
            dp[b][g][r] |= dfs(b + 1, g - 1, r - 1);
    }

    return dp[b][g][r];
}

int main()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    int b = 0, g = 0, r = 0;
    for (auto it: str)
        if (it == 'B')
            ++ b;
        else if (it == 'G')
            ++ g;
        else
            ++ r;

    int ans = dfs(b, g, r);

    if (ans & 4)
        cout << 'B';
    if (ans & 2)
        cout << 'G';
    if (ans & 1)
        cout << 'R';
    cout << '\n';

    return 0;
}