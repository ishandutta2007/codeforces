#include<bits/stdc++.h>

using namespace std;

const int MaxN = 1e5 + 15;
const int MOD = 1e9 + 7;

int ans = 1e6;

int getMin(int x)
{
    int res = x;

    int X = x;

    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0)
        {
            int p = i;

            while(x % i == 0)
                x /= i;

            if(X == p)
                continue;

            int Y = X - p + 1;

            res = min(res, Y);
        }

    if(x != 1)
    {
        int p = x;

        if(X != p)
        {
            int Y = X - p + 1;

            res = min(res, Y);
        }
    }

    return res;
}

void solve(int x)
{
    ans = getMin(x);

    int maxP = 1;


    int X = x;
    for(int i = 2; i * i <= X; ++i)
        if(X % i == 0)
        {
            maxP = max(maxP, i);
            while(X % i == 0)
                X /= i;
        }

    if(X != 1)
        maxP = max(maxP, X);

    for(int i = x - maxP + 1; i <= x; ++i)
        ans = min(ans, getMin(i));
}

int main()
{
//    freopen("input.txt", "r", stdin);

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    solve(n);

    cout << ans << '\n';

    return 0;
}