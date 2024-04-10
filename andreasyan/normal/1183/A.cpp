#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    int ans = 0;
    while (n)
    {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = n; ; ++i)
    {
        if (sum(i) % 4 == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}