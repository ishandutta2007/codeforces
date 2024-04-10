#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int S1 = 0, S2 = 0;

    for (int i = 1; i <= 3; i++)
    {
        int x;
        cin >> x;

        S1 += x;
    }

    for (int i = 1; i <= 3; i++)
    {
        int x;
        cin >> x;

        S2 += x;
    }

    int N;
    cin >> N;

    int M = S1 / 5 + (S1 % 5 > 0) + S2 / 10 + (S2 % 10 > 0);

    if (M <= N) cout << "YES\n";
    else cout << "NO\n";

}