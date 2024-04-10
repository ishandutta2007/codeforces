#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

int N, K;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> K;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x > 3 * K)
            sum += x - 3 * K;
        else
            sum += x % K;
    }
    cout << sum << endl;

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}