#include <bits/stdc++.h>
using namespace std;
const int N = 10000007;

int a, n;

int ans[N];
int main()
{
    cin >> a >> n;
    for (int i = 1; 1LL * i * i < N; ++i)
    {
        if (i * i * 1LL < N)
        {
            int x = i * i;
            for (int j = x; j < N; j += x)
            {
                ans[j] = x;
            }
        }
    }

    long long yans = 0;
    for (int i = a; i < a + n; ++i)
        yans += (i / ans[i]);
    cout << yans << endl;
    return 0;
}