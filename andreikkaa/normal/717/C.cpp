#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int x[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    sort(x, x + n);
    long long int S = 0;
    for (int i = 0; i < n; ++i)
    {
        S += x[i] * x[n-1-i];
    }
    cout << S % 10007;
    return 0;
}